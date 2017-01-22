// ��������Ҫ�����ж���������������Ŵ���ǽ������������¥�壩
// ����Ϊnwd�ļ���Navisworks��
// ��Ҫ���������Ƭ
// ��������OpenCascade��Դ�⣬�����ͣ��������Ĳ�������������Ȼ��
// �����ʷ֣��ؼ�����Ҫ��һ������������е�������Ƭ
// �����ϴ�������ÿ�Դ��
// ���Ըý����������
// PS. ���˸о�OpenCascade��һ���ǳ�ǿ�������ʹ�õĿ�������
// �ĵ���ȫ��ʾ���ḻ�����������ǿ�ϧ����

// �����ʷ�
// �����ж��Ľ����ڵ�����nwd�ļ�ʱ����ʧ�����⣺1292293# ʵ�嵼����NV����ǽ�忪����ʧ
// ʹ��OpenCascade���ͣ�Ȼ�������ʷֻ�����е�������Ƭ

#pragma once

// inc/PlaneInc/aslib.h �е�iso�������׼���е�ios�����ͻ
#ifdef ios
	#undef ios
#endif

#include <MetaBoxEntity.h>
#include <boost/smart_ptr.hpp>
#include <TopoDS_Shape.hxx>

typedef boost::shared_ptr<AcGePoint3dArray> AcGePoint3dArrayPtr;

class ZWTriangulation
{
public:
	ZWTriangulation();
	~ZWTriangulation();

	void Triangulation(const CMetaBoxEntity* metaBox);
	AcGePoint3dArrayPtr GetFacets();

private:
	// ����
	void DealWithHoles(const CMetaBoxEntity* metaBox);

private:
	TopoDS_Shape mShape;
};

