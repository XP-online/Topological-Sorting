// stdafx.cpp : source file that includes just the standard includes
// ͼ�����ݽṹ.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
//�����޸����²���
//��֧����1
void initGraph(Graph* pGraph)//��֧����
{//��֧����
	//��ʼ��ͼ�Ľڵ�
	for (int i = 1; i <= 7;i++)
	{
		Vertex* ver = nullptr;
		 = new Vertex(i);
		pGraph->addtoGraph(ver);
		//�г�ͼ�ĵĶ���
	//	printf("%d\n", ver->itNum());
	}

	//����ͼ�Ľṹ

	//������numΪ1�Ķ���Ϊ��ʼ�ı�
	int nextList1[] = { 2, 4, 3 };
	pGraph->addNextVertexInGraph(pGraph->number(1), nextList1, 3);

	//������numΪ2�Ķ���Ϊ��ʼ�ı�
	int nextList2[] = { 4, 5 };
	pGraph->addNextVertexInGraph(pGraph->number(2), nextList2, 2);

	//������numΪ3�Ķ���Ϊ��ʼ�ı�
	int nextList3[] = { 6 };
	pGraph->addNextVertexInGraph(pGraph->number(3), nextList3, 1);

	//������numΪ4�Ķ���Ϊ��ʼ�ı�
	int nextList4[] = { 6, 7, 3};
	pGraph->addNextVertexInGraph(pGraph->number(4), nextList4, 3);

	//������numΪ5�Ķ���Ϊ��ʼ�ı�
	int nextList5[] = { 4, 7 };
	pGraph->addNextVertexInGraph(pGraph->number(5), nextList5, 2);

	//������numΪ6�Ķ���Ϊ��ʼ�ı�
	//��

	//������numΪ7�Ķ���Ϊ��ʼ�ı�
	int nextList7[] = { 6 };
	pGraph->addNextVertexInGraph(pGraph->number(7), nextList7, 1);
	/*
	//����
	pGraph->removeFromGraph(4);
	//��ӡ����ͼ���ڽӱ�
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
