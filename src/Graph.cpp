
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
//��һ���µĶ�����뵽ͼ�С�
bool Graph::addtoGraph(Vertex* ver)
{
	if (!ver)
	{
		return false;
	}
	m_VertexList.push_back(ver);
	return true;
}
//��ͼ���ҵ�verָ��Ķ��㲢ɾ��ɾ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false����
bool Graph::removeFromGraph(Vertex* ver)
{
	if (!ver)
	{
		//printf("û���ҵ�Ҫɾ���Ľڵ㣡");	
		return false;
	}
	std::list<Vertex*>::const_iterator it = m_VertexList.begin();
	for (; it != m_VertexList.end(); it++)
	{
		if (!(*it))	//��ֹ�ö���Ϊ��ָ��
		{
			continue;
		}

		if ((*it)->itNum() == ver->itNum())
		{
			it = m_VertexList.erase(it);		//ɾ�����ΪNum��Ԫ��

			if (it == m_VertexList.end())	//��ɾ���Ķ���Ϊ���һ��Ԫ��break��
			{
				break;
			}
			if (!(*it))	//��ֹ�ö���Ϊ��ָ��
			{
				continue;
			}
		}
		
		if ((*it)->isNextNum(ver->itNum()))		//ɾ������Ԫ����ָ��NumԪ�ص�ָ��
		{
			(*it)->removeNextVertex(ver->itNum());
		}
	}

	return true;
}
//��ͼ���ҵ����Ϊnum�Ķ��㲢ɾ��ɾ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false����
bool Graph::removeFromGraph(int num)
{
	Vertex* ver = this->number(num);
	if (!ver)
	{
		//printf("û���ҵ�Ҫɾ���Ľڵ㣡");
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

	if (it == m_VertexList.end())		//�ж������Ƿ�Ϊ��
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
//����һ���µ�·��ָ��һ���µĽڵ㡣
bool Vertex::addNextVertex(Vertex* ver)
{
	if (!ver)
	{
		return false;
	}
	m_pNextList.push_back(ver);
	return true;
}

//��ͼ���ҵ����Ϊnum�Ķ��㲢ɾ��ɾ��������ɹ�ɾ���򷵻�true,ʧ�ܷ���false����
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
//���ض��������(m_Data)
int Vertex::itData()
{
	return m_Data;
}
//���ض���ı�ţ�m_Num��
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
