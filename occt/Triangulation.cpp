// OpenCascade
// 对模型进行三角剖分，获得三角形面片

// 以一个Box为例
gp_Pnt pt1(0, 0, 0);
gp_Pnt pt2(800, 0, 0);
gp_Pnt pt3(800, 600, 0);
gp_Pnt pt4(0, 600, 0);

// 底面的四条线段
Handle(Geom_TrimmedCurve) segment1 = GC_MakeSegment(pt1, pt2);
Handle(Geom_TrimmedCurve) segment2 = GC_MakeSegment(pt2, pt3);
Handle(Geom_TrimmedCurve) segment3 = GC_MakeSegment(pt3, pt4);
Handle(Geom_TrimmedCurve) segment4 = GC_MakeSegment(pt4, pt1);

// 由线段创建Edge shape
TopoDS_Edge edge1 = BRepBuilderAPI_MakeEdge(segment1);
TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(segment2);
TopoDS_Edge edge3 = BRepBuilderAPI_MakeEdge(segment3);
TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(segment4);

// 将Edge连接为Wire shape
TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge1, edge2, edge3, edge4);

// 由Wire生成Face shape，即底面
TopoDS_Face bottomFace = BRepBuilderAPI_MakeFace(wire);

// 将Face沿高方向挤出
gp_Vec prismVec(0, 0, 500);
TopoDS_Shape box = BRepPrimAPI_MakePrism(bottomFace, prismVec);

Handle(AIS_Shape) ais99 = new AIS_Shape(box);
myAISContext->Display(ais99, Standard_False);

// 三角剖分
BRepMesh_IncrementalMesh mesh(box, 0.1);

TopExp_Explorer explorer(box, TopAbs_FACE);
for (; explorer.More(); explorer.Next())
{
	// 获得所有Face，然后获得Face的三角剖分结果
	TopoDS_Face face = TopoDS::Face(explorer.Current());
	TopLoc_Location loc;
	Handle(Poly_Triangulation) polyTri = BRep_Tool::Triangulation(face, loc);

	if (polyTri.IsNull())
		continue;

	TColgp_Array1OfPnt vertices = polyTri->Nodes();        // 顶点
	Poly_Array1OfTriangle indices = polyTri->Triangles();  // 顶点索引

	for (int i = 0; i < indices.Size(); ++i)
	{
		// 索引不是从0开始的
		Poly_Triangle triangle = indices.Value(indices.Lower() + i);
		gp_Pnt pt1 = vertices.Value(triangle.Value(1)).Transformed(loc);
		gp_Pnt pt2 = vertices.Value(triangle.Value(2)).Transformed(loc);
		gp_Pnt pt3 = vertices.Value(triangle.Value(3)).Transformed(loc);

		// pt1, pt2, pt3即为一个三角形面片
		// .Transformed(loc); // 这一步操作是必须的，不要遗漏
	}
}
