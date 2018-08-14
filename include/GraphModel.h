#pragma once
#include "Graph.h"
#define NotAVertex -1
class GraphModel
{
public:
	GraphModel();
	~GraphModel();
	//返回graph中的一个没有被指向的节点，如果没有返回'-1'
	int FindNewVertexOfIndegreeZero(Graph* graph);
	//拓扑排序
	void Topsort(Graph* graph);
};

