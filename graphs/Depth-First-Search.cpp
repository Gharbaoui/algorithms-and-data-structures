#include "Graph.hpp"

// graph algorithms
void	Graph::DepthFirstTraversal(int start, const std::function<void (int)> &excute)
{
	InitArrsBool(MX_VERTEX);
	int 		proccessed;
	std::list<int>	unProccessedVertices;
	
	unProccessedVertices.push_front(start);
	aVisited[start] = true;
	while (!unProccessedVertices.empty())
	{
		// if top is not proccessed proccess it (like print it for example or delete)
		// then mark it as proccessed
		proccessed = unProccessedVertices.back();
		unProccessedVertices.pop_back();
		if (!aProccessed[proccessed])
		{
			aProccessed[proccessed] = true;
			excute(proccessed);
		}
		DFSAddNeighToBeProccessed(proccessed, unProccessedVertices);
	}
	std::cout << std::endl;
}

void	Graph::DFSAddNeighToBeProccessed(int index, std::list<int> &unProccessedVertices)
{
	Vertex	*tmp;
	
	tmp = apVertices[index];
	while (tmp)
	{
		if (!aVisited[tmp->GetVertexId()])
		{
			unProccessedVertices.push_back(tmp->GetVertexId());
			aVisited[tmp->GetVertexId()] = true;
		}
		tmp = tmp->GetNextVertex();
	}
}
