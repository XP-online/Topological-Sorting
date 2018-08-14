//	图数据结构：（邻接法）
//	图的组成			顶点集：	V(vertex)		边集：		E(edge)
//	顶点的组成		顶点的编号(num)，顶点存储的数据(data)
//	边的组成			每一条边就是一个点对（v,w）,v,w∈V
#pragma once

#include <list>


/*
顶点类:
	int m_Num		顶点的编号
	int m_Data	顶点的数据
	std::list<vertex*> m_pNextList	该顶点的所指向的顶点列表
*/
class Vertex
{
public:
	Vertex(int num);
	Vertex(int num, int data);
	Vertex(int num, int data, std::list <Vertex*> nextlist);
	~Vertex();
	bool addNextVertex(Vertex* ver);	//增加一个新的路径，指向一个新的节点。

	bool removeNextVertex(int num);	//从图中找到编号为num的顶点并删除删除（如果成功删除则返回true,失败返回false）。
	
	std::list<int> getNextNumList();	//获取该顶点的指向的顶点链表，没有则为空链表
	
	int itNum();	//返回顶点的编号（m_Num）

	int itData();		//返回顶点的数据(m_Data)

	bool isNextNum(int num);	//判断num的节点是否是该节点所指向的节点
protected:
	
private:
	int m_Num;	//顶点的编号
	int m_Data;	//顶点的数据
	std::list <Vertex*> m_pNextList;	//该顶点的所指向的顶点列表
};

//图的表示：
//m_VertexList	所有顶点的列表
class Graph
{
public:
	Graph();
	Graph(std::list<Vertex*> vertexList);	//vertexList所有顶点的指针链表
	~Graph();

	bool addtoGraph(Vertex* ver);	//将一个新的顶点加入到图中。

	bool removeFromGraph(int num);	//从图中找到编号为num的顶点并删除删除（如果成功删除则返回true,失败返回false）。

	//为ver顶点增加next顶点（next顶点为在图中的顶点，且编号为numList中的一员），如果成功删除则返回true,失败返回false.
	bool addNextVertexInGraph(Vertex* ver, int numList[], int size);	

	Vertex* at(int n) const;	//返回m_VertexList的第n个顶点，如果超出了链表的大小返回空指针。

	Vertex* number(int num) const;	//返回编号为num的顶点，如果未找到返回空指针。

	std::list<int> getVertexList();	//返回左右顶点的链表，没有则为空表。
protected:
	//从图中找到ver指向的顶点并删除删除（如果成功删除则返回true,失败返回false）。
	bool removeFromGraph(Vertex* ver);	
private:
	std::list<Vertex*> m_VertexList;	//所有顶点的列表
	
};
