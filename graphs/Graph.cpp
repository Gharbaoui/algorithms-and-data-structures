#include "Graph.hpp"
// constructors
Graph::Graph(unsigned int nv, unsigned int ne)
{
	aNumvertices = nv;
	aNumEdges = ne;
	InitVertices(MX_VERTEX);
}

Graph::Graph()
{
	InitVertices(MX_VERTEX);
}

// private functions in graph
void	Graph::FillArrBool(bool *arr, bool value, int n)
{
	for (int i = 0; i < n; ++i)
		arr[i] = value;
}

void	Graph::InitArrsBool(int n)
{
	for (int i = 0; i < n; ++i)
	{
		aProccessed[i] = false;
		aVisited[i] = false;
	}
}

void	Graph::InitVertices(int n)
{
	for (int i = 0; i < n; ++i)
		apVertices[i] = NULL_PTR;
}

// OPERATIONS
void	Graph::Insert(const std::pair<int,int> &edge)
{
	PrInsert(edge);
	PrInsert(std::pair<int, int>(edge.second, edge.first));
}

void	Graph::PrInsert(const std::pair<int, int> &edge)
{
	Vertex *tmp;
	
	tmp = aVertexAlloc.allocate(1);
	aVertexAlloc.construct(tmp, edge.second);
	tmp->SetNextVertex(apVertices[edge.first]);
	apVertices[edge.first] = tmp;
}

void Graph::display()
{
	Vertex *tmp;
	for (int i = 0; i < MX_VERTEX; ++i)
	{
		tmp = apVertices[i];
		if (tmp)
			std::cout << "\033[1;31m{ " << i << " }\033[0m";
		else
			continue ;
		while (tmp)
		{
			std::cout << " -> (" << tmp->GetVertexId() << ")";
			tmp = tmp->GetNextVertex();
		}
		std::cout << std::endl;
	}
}
