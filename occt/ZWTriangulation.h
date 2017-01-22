// 工作中需要将带有洞建筑（比如带有门窗的墙、经过开洞的楼板）
// 导出为nwd文件（Navisworks）
// 需要获得三角面片
// 故引入了OpenCascade开源库，先造型（包括洞的布尔减操作），然后
// 三角剖分（关键是需要这一步），获得所有的三角面片
// 但是老大不让引入该开源库
// 所以该解决方案被弃
// PS. 个人感觉OpenCascade是一个非常强大和易于使用的开发包，
// 文档齐全，示例丰富，不让用真是可惜啊。

// 三角剖分
// 处理有洞的建筑在导出到nwd文件时洞消失的问题：1292293# 实体导出和NV导出墙体开洞丢失
// 使用OpenCascade造型，然后三角剖分获得所有的三角面片

#pragma once

// inc/PlaneInc/aslib.h 中的iso定义与标准库中的ios定义冲突
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
	// 开洞
	void DealWithHoles(const CMetaBoxEntity* metaBox);

private:
	TopoDS_Shape mShape;
};

