#include "StdAfx.h"
#include "ZWTriangulation.h"
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS.hxx>
#include <BRep_Tool.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeSegment.hxx>
#include <BRepAlgoAPI_Cut.hxx>

#pragma comment(lib, "TKPrim.lib")
#pragma comment(lib, "TKBRep.lib")
#pragma comment(lib, "TKernel.lib")
#pragma comment(lib, "TKMath.lib")
#pragma comment(lib, "TKTopAlgo.lib")
#pragma comment(lib, "TKMesh.lib")
#pragma comment(lib, "TKG3d.lib")
#pragma comment(lib, "TKGeomBase.lib")
#pragma comment(lib, "TKBO.lib")


ZWTriangulation::ZWTriangulation()
{
}


ZWTriangulation::~ZWTriangulation()
{
}

void ZWTriangulation::Triangulation(const CMetaBoxEntity* metaBox)
{
	try
	{
		// ����GetVertices��ʵ�֣�һ��10�����㣬ǰ����ǵ���Ķ��㣬��1���͵�5����ͬ
		AcGePoint3dArray vertices;
		metaBox->GetVertices(vertices);
		if (vertices.length() != 10)
			return;

		AcGeVector3d heightOffset = vertices[5] - vertices[0];

		gp_Pnt pt1(vertices[0].x, vertices[0].y, vertices[0].z);
		gp_Pnt pt2(vertices[1].x, vertices[1].y, vertices[1].z);
		gp_Pnt pt3(vertices[2].x, vertices[2].y, vertices[2].z);
		gp_Pnt pt4(vertices[3].x, vertices[3].y, vertices[3].z);

		// ����������߶�
		Handle(Geom_TrimmedCurve) segment1 = GC_MakeSegment(pt1, pt2);
		Handle(Geom_TrimmedCurve) segment2 = GC_MakeSegment(pt2, pt3);
		Handle(Geom_TrimmedCurve) segment3 = GC_MakeSegment(pt3, pt4);
		Handle(Geom_TrimmedCurve) segment4 = GC_MakeSegment(pt4, pt1);

		// ���߶δ���Edge shape
		TopoDS_Edge edge1 = BRepBuilderAPI_MakeEdge(segment1);
		TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(segment2);
		TopoDS_Edge edge3 = BRepBuilderAPI_MakeEdge(segment3);
		TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(segment4);

		// ��Edge����ΪWire shape
		TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge1, edge2, edge3, edge4);

		// ��Wire����Face shape��������
		TopoDS_Face bottomFace = BRepBuilderAPI_MakeFace(wire);

		// ��Face�ظ߷��򼷳�
		gp_Vec prismVec(heightOffset.x, heightOffset.y, heightOffset.z);
		mShape = BRepPrimAPI_MakePrism(bottomFace, prismVec);
		if (mShape.IsNull())
			return;

		// �Զ����в�������
		DealWithHoles(metaBox);
	}
	catch (...)
	{
		acutPrintf(_T("OCCT: Failed!"));
	}
}

AcGePoint3dArrayPtr ZWTriangulation::GetFacets()
{
	AcGePoint3dArrayPtr ret(new AcGePoint3dArray);
	if (mShape.IsNull())
		return ret;

	try
	{
		BRepMesh_IncrementalMesh mesh(mShape, 0.1);

		TopExp_Explorer explorer(mShape, TopAbs_FACE);
		for (; explorer.More(); explorer.Next())
		{
			// �������Face��Ȼ����Face�������ʷֽ��
			TopoDS_Face face = TopoDS::Face(explorer.Current());
			TopLoc_Location loc;
			Handle(Poly_Triangulation) polyTri = BRep_Tool::Triangulation(face, loc);

			if (polyTri.IsNull())
				continue;

			TColgp_Array1OfPnt vertices = polyTri->Nodes();        // ����
			Poly_Array1OfTriangle indices = polyTri->Triangles();  // ��������

			for (int i = 0; i < indices.Size(); ++i)
			{
				// �������Ǵ�0��ʼ��
				Poly_Triangle triangle = indices.Value(indices.Lower() + i);
				gp_Pnt pt1 = vertices.Value(triangle.Value(1)).Transformed(loc);
				gp_Pnt pt2 = vertices.Value(triangle.Value(2)).Transformed(loc);
				gp_Pnt pt3 = vertices.Value(triangle.Value(3)).Transformed(loc);

				ret->append(AcGePoint3d(pt1.X(), pt1.Y(), pt1.Z()));
				ret->append(AcGePoint3d(pt2.X(), pt2.Y(), pt2.Z()));
				ret->append(AcGePoint3d(pt3.X(), pt3.Y(), pt3.Z()));
			}
		}
	}
	catch (...)
	{
		acutPrintf(_T("OCCT: Failed!"));
	}

	return ret;
}

void ZWTriangulation::DealWithHoles(const CMetaBoxEntity* metaBox)
{
	IcDynArray<XPoly2D*> holes = metaBox->getHole2dArry();
	if (holes.IsEmpty())
		return;

	// ��Ҫ��Poly�ض����򼷳�Ϊ�壬Ȼ�������Box���в���������
	// ����XPoly2D��λ��Box���ģ�����֮ǰ����Ҫ�Ƚ�Poly��ƫ�Ƶ�Box֮��
	AcDbExtents extents;
	metaBox->getGeomExtents(extents);

	double offsetDist = extents.maxPoint().x - extents.minPoint().x;
	offsetDist = (std::max)(offsetDist, extents.maxPoint().y - extents.minPoint().y);
	offsetDist = (std::max)(offsetDist, extents.maxPoint().z - extents.minPoint().z);

	AcGeVector3d holeDirection = metaBox->getHoleVec().normal();

	AcGeMatrix3d translation;
	translation.setToTranslation(-holeDirection * offsetDist);

	// �������ж�
	for (int idxHole = 0; idxHole < holes.GetLength(); ++idxHole)
	{
		// Poly���ܻ��л��Σ���������ɢ��
		XPoly2D poly;
		holes[idxHole]->Disperse(poly);

		if (poly.Length() < 3)
			continue;

		// ��
		AcArray<gp_Pnt> points;
		for (int idxPt = 0; idxPt < poly.Length(); ++idxPt)
		{
			 XPoint pt = *poly[idxPt];
			 pt.TransformBy(translation);
			 points.append(gp_Pnt(pt.x, pt.y, pt.z));
		}
		// Ϊ�˱��ڴ�������һ������ӵ���β
		points.append(points[0]);

		// �������ӳ��߶�
		AcArray<Handle(Geom_TrimmedCurve)> segments;
		for (int idxPt = 0; idxPt < points.length() - 1; ++idxPt)
		{
			segments.append(GC_MakeSegment(points[idxPt], points[idxPt + 1]));
		}

		// ���߶δ���Edge -> Wire
		BRepBuilderAPI_MakeWire mkWire;
		for (int idxSeg = 0; idxSeg < segments.length(); ++idxSeg)
		{
			TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(segments[idxSeg]);
			mkWire.Add(edge);
		}
		TopoDS_Wire wire = mkWire.Wire();

		// ��Wire����Face
		TopoDS_Face face = BRepBuilderAPI_MakeFace(wire);

		// �漷��
		AcGeVector3d offsetDirection = holeDirection * offsetDist * 2.0;
		gp_Vec prismVec(offsetDirection.x, offsetDirection.y, offsetDirection.z);
		TopoDS_Shape holeShape = BRepPrimAPI_MakePrism(face, prismVec);

		// ����������
		mShape = BRepAlgoAPI_Cut(mShape, holeShape);
	}
}
