#pragma once
#include "Graph.h"
#define NotAVertex -1
class GraphModel
{
public:
	GraphModel();
	~GraphModel();
	//����graph�е�һ��û�б�ָ��Ľڵ㣬���û�з���'-1'
	int FindNewVertexOfIndegreeZero(Graph* graph);
	//��������
	void Topsort(Graph* graph);
};

