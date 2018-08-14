//	ͼ���ݽṹ�����ڽӷ���
//	ͼ�����			���㼯��	V(vertex)		�߼���		E(edge)
//	��������		����ı��(num)������洢������(data)
//	�ߵ����			ÿһ���߾���һ����ԣ�v,w��,v,w��V
#pragma once

#include <list>


/*
������:
	int m_Num		����ı��
	int m_Data	���������
	std::list<vertex*> m_pNextList	�ö������ָ��Ķ����б�
*/
class Vertex
{
public:
	Vertex(int num);
	Vertex(int num, int data);
	Vertex(int num, int data, std::list <Vertex*> nextlist);
	~Vertex();
	bool addNextVertex(Vertex* ver);	//����һ���µ�·����ָ��һ���µĽڵ㡣

	bool removeNextVertex(int num);	//��ͼ���ҵ����Ϊnum�Ķ��㲢ɾ��ɾ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false����
	
	std::list<int> getNextNumList();	//��ȡ�ö����ָ��Ķ�������û����Ϊ������
	
	int itNum();	//���ض���ı�ţ�m_Num��

	int itData();		//���ض��������(m_Data)

	bool isNextNum(int num);	//�ж�num�Ľڵ��Ƿ��Ǹýڵ���ָ��Ľڵ�
protected:
	
private:
	int m_Num;	//����ı��
	int m_Data;	//���������
	std::list <Vertex*> m_pNextList;	//�ö������ָ��Ķ����б�
};

//ͼ�ı�ʾ��
//m_VertexList	���ж�����б�
class Graph
{
public:
	Graph();
	Graph(std::list<Vertex*> vertexList);	//vertexList���ж����ָ������
	~Graph();

	bool addtoGraph(Vertex* ver);	//��һ���µĶ�����뵽ͼ�С�

	bool removeFromGraph(int num);	//��ͼ���ҵ����Ϊnum�Ķ��㲢ɾ��ɾ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false����

	//Ϊver��������next���㣨next����Ϊ��ͼ�еĶ��㣬�ұ��ΪnumList�е�һԱ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false.
	bool addNextVertexInGraph(Vertex* ver, int numList[], int size);	

	Vertex* at(int n) const;	//����m_VertexList�ĵ�n�����㣬�������������Ĵ�С���ؿ�ָ�롣

	Vertex* number(int num) const;	//���ر��Ϊnum�Ķ��㣬���δ�ҵ����ؿ�ָ�롣

	std::list<int> getVertexList();	//�������Ҷ��������û����Ϊ�ձ�
protected:
	//��ͼ���ҵ�verָ��Ķ��㲢ɾ��ɾ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false����
	bool removeFromGraph(Vertex* ver);	
private:
	std::list<Vertex*> m_VertexList;	//���ж�����б�
	
};
