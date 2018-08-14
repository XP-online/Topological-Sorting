#include "stdafx.h"
#include "GraphModel.h"

using namespace std;

GraphModel::GraphModel()
{
}


GraphModel::~GraphModel()
{
}

int GraphModel::FindNewVertexOfIndegreeZero(Graph* graph)
{
	std::list <int> graVertexList = graph->getVertexList();
	int n = graVertexList.size();
	Vertex* pVerI = NULL;
	Vertex* pVerJ = NULL;
	for (int i = 0; i < n; i++)
	{
		pVerI = graph->at(i);
		if (!pVerI)	//判断该顶点有效
		{
			continue;
		}
		int j = 0;
		for (; j < n; j++)
		{
			pVerJ = graph->at(j);
			if (!pVerJ)	//判断该顶点有效
			{
				continue;
			}
			if (pVerJ->isNextNum(pVerI->itNum()))
			{
				break;
			}
		}
		if (j == n)
		{
			return pVerI->itNum();
		}

	}
	return -1;
}

void GraphModel::Topsort(Graph* graph)
{
	std::list<int> verList = graph->getVertexList();
	int n = verList.size();
	cout << "Topsort:";
	for (int i = 0; i < n; i++)
	{
		int num = FindNewVertexOfIndegreeZero(graph);
		graph->removeFromGraph(num);
		cout << " " << num;
	}
	cout << endl;
}
