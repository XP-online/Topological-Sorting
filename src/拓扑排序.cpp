// Õÿ∆À≈≈–Ú.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GraphModel.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Graph* pGraph = new Graph;
	initGraph(pGraph);
	GraphModel model;
	//int n = model.FindNewVertexOfIndegreeZero(pGraph);
	model.Topsort(pGraph);
	system("pause");
	return 0;
}

