#include "Graph.hpp"

// graph algorithms
void	Graph::BreathFirstTraversal(int start, const std::function<void (int)> &excute)
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
		proccessed = unProccessedVertices.front();
		unProccessedVertices.pop_front();
		if (!aProccessed[proccessed])
		{
			aProccessed[proccessed] = true;
			excute(proccessed);
		}
		BFSAddNeighToBeProccessed(proccessed, unProccessedVertices);
	}
	std::cout << std::endl;
}

void	Graph::BFSAddNeighToBeProccessed(int index, std::list<int> &unProccessedVertices)
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
