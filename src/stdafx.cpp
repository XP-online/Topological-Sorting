// stdafx.cpp : source file that includes just the standard includes
// 图的数据结构.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
//测试修改重新测试
//分支测试1
void initGraph(Graph* pGraph)//分支增加
{//分支增加
	//初始化图的节点
	for (int i = 1; i <= 7;i++)
	{
		Vertex* ver = nullptr;
		 = new Vertex(i);
		pGraph->addtoGraph(ver);
		//列出图的的顶点
	//	printf("%d\n", ver->itNum());
	}

	//构建图的结构

	//构建以num为1的顶点为起始的边
	int nextList1[] = { 2, 4, 3 };
	pGraph->addNextVertexInGraph(pGraph->number(1), nextList1, 3);

	//构建以num为2的顶点为起始的边
	int nextList2[] = { 4, 5 };
	pGraph->addNextVertexInGraph(pGraph->number(2), nextList2, 2);

	//构建以num为3的顶点为起始的边
	int nextList3[] = { 6 };
	pGraph->addNextVertexInGraph(pGraph->number(3), nextList3, 1);

	//构建以num为4的顶点为起始的边
	int nextList4[] = { 6, 7, 3};
	pGraph->addNextVertexInGraph(pGraph->number(4), nextList4, 3);

	//构建以num为5的顶点为起始的边
	int nextList5[] = { 4, 7 };
	pGraph->addNextVertexInGraph(pGraph->number(5), nextList5, 2);

	//构建以num为6的顶点为起始的边
	//无

	//构建以num为7的顶点为起始的边
	int nextList7[] = { 6 };
	pGraph->addNextVertexInGraph(pGraph->number(7), nextList7, 1);
	/*
	//测试
	pGraph->removeFromGraph(4);
	//打印整个图的邻接表
	for (int i = 1; i <= 7; i++)
	{
		Vertex* ver = pGraph->number(i);
		if (ver)
		{
			
			std::list<int> nextNumList = ver->getNextNumList();
			std::list<int>::const_iterator it = nextNumList.begin();
			printf("The nextListNum of %d vertext is ", ver->itNum());

			if (it == nextNumList.end())
			{
				printf("empty");
			}

			for (; it != nextNumList.end(); it++)
			{
				printf("%d ", *it);
			}
			printf("\n");
		}
	}
	*/
}
