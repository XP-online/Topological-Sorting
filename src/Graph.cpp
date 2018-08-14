
#include "Graph.h"
#include "stdafx.h"

Graph::Graph()
{
}

Graph::Graph(std::list<Vertex*> vertexList)
{
	m_VertexList = vertexList;
}


Graph::~Graph()
{
}
//将一个新的顶点加入到图中。
bool Graph::addtoGraph(Vertex* ver)
{
	if (!ver)
	{
		return false;
	}
	m_VertexList.push_back(ver);
	return true;
}
//从图中找到ver指向的顶点并删除删除（如果成功删除则返回true,失败返回false）。
bool Graph::removeFromGraph(Vertex* ver)
{
	if (!ver)
	{
		//printf("没有找到要删除的节点！");	
		return false;
	}
	std::list<Vertex*>::const_iterator it = m_VertexList.begin();
	for (; it != m_VertexList.end(); it++)
	{
		if (!(*it))	//防止该顶点为空指针
		{
			continue;
		}

		if ((*it)->itNum() == ver->itNum())
		{
			it = m_VertexList.erase(it);		//删除编号为Num的元素

			if (it == m_VertexList.end())	//若删除的顶点为最后一个元素break；
			{
				break;
			}
			if (!(*it))	//防止该顶点为空指针
			{
				continue;
			}
		}
		
		if ((*it)->isNextNum(ver->itNum()))		//删除其他元素所指向Num元素的指针
		{
			(*it)->removeNextVertex(ver->itNum());
		}
	}

	return true;
}
//从图中找到编号为num的顶点并删除删除（如果成功删除则返回true,失败返回false）。
bool Graph::removeFromGraph(int num)
{
	Vertex* ver = this->number(num);
	if (!ver)
	{
		//printf("没有找到要删除的节点！");
		return false;
	}
	return removeFromGraph(ver);
}

Vertex* Graph::at(int n) const
{
	if (n >= (int)m_VertexList.size())
	{
		//printf("Out of GraphSize!\n");
		return NULL;
	}
	std::list<Vertex*>::const_iterator it = m_VertexList.begin();
	std::advance(it, n);
	return *it;
}

Vertex* Graph::number(int num) const
{
	std::list<Vertex*>::const_iterator it = m_VertexList.begin();
	for (; it != m_VertexList.end(); it++)
	{
		if ((*it)->itNum() == num)
			return *it;
	}
	//printf("Don't have the vertex which the num is %d\n", num);
	return NULL;
}

bool Graph::addNextVertexInGraph(Vertex* ver, int numList[], int size)
{

	for (int i = 0; i < size; i++)
	{
		Vertex* nextVer = number(numList[i]);
		if (!nextVer){
			//printf("Dont't have the vertex in graph which the num is %d.\n", numList[i]);
			return false;	
		}
		ver->addNextVertex(nextVer);
	}
	return true;
}

std::list<int> Graph::getVertexList()
{
	std::list<Vertex*>::iterator it = m_VertexList.begin();
	std::list<int> vertexList = {};

	if (it == m_VertexList.end())		//判断链表是否为空
	{
		return vertexList;
	}

	for (; it != m_VertexList.end(); it++)
	{
		vertexList.push_back((*it)->itNum());
	}
	return vertexList;
}

Vertex::Vertex(int num)
{
	m_Num = num;
	m_Data = 0;
}

Vertex::Vertex(int num, int data)
{

}

Vertex::Vertex(int num, int data, std::list <Vertex*> nextlist)
{
	m_Num = num;
	m_Data = data;
	m_pNextList = nextlist;
}

Vertex::~Vertex()
{
}
//增加一个新的路径指向一个新的节点。
bool Vertex::addNextVertex(Vertex* ver)
{
	if (!ver)
	{
		return false;
	}
	m_pNextList.push_back(ver);
	return true;
}

//从图中找到编号为num的顶点并删除删除（如果成功删除则返回true,失败返回false）。
bool Vertex::removeNextVertex(int num)
{
	std::list <Vertex*>::const_iterator it = m_pNextList.begin();
	for (; it != m_pNextList.end(); it++)
	{
		if ((*it)->itNum() == num)
		{
			m_pNextList.erase(it);
			return true;
		}
	}
	return false;
}
//返回顶点的数据(m_Data)
int Vertex::itData()
{
	return m_Data;
}
//返回顶点的编号（m_Num）
int Vertex::itNum()
{
	return m_Num;
}

std::list<int> Vertex::getNextNumList()
{
	std::list<Vertex*>::iterator it = m_pNextList.begin();
	std::list<int> nextNumList = {};
//	printf("The nextListNum of %d vertext is ", this->m_Num);

	if (it == m_pNextList.end())
	{
//		printf("empty\n");
		return nextNumList;
	}

	for (; it != m_pNextList.end(); it++)
	{
		nextNumList.push_back((*it)->itNum());
//		printf("%d ", (*it)->itNum());
	}
//	printf("\n");
	return nextNumList;
}

bool Vertex::isNextNum(int num)
{
	std::list<int> nextNumList = getNextNumList();
	std::list<int>::const_iterator it = nextNumList.begin();
	for (; it != nextNumList.end(); it++)
	{
		if ((*it) == num)
		{
			return true;
		}
	}
	return false;
}
