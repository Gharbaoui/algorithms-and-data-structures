#include "Graph.hpp"

// shortest path with breath first search
void	Graph::BFShortestPath(int start, int end)
{
	InitArrsBool(MX_VERTEX);
	std::list <int> unPorccessedVertices;
	Vertex		*tmp;
	int	proccessed;
	std::list<std::pair<int, int> > routTrack;

	unPorccessedVertices.push_back(start);
	aVisited[start] = true;
	while (!unPorccessedVertices.empty())
	{
		if (unPorccessedVertices.back() == end)
			break ;
		proccessed = unPorccessedVertices.front();
		unPorccessedVertices.pop_front();
		if (!aProccessed[proccessed])
			aProccessed[proccessed] = true;
		tmp = apVertices[proccessed];
		while (tmp)
		{
			if (!aVisited[tmp->GetVertexId()])
			{
				aVisited[tmp->GetVertexId()] = true;
				unPorccessedVertices.push_back(tmp->GetVertexId());
				routTrack.push_back(std::make_pair(proccessed, tmp->GetVertexId()));
			}
			if (tmp->GetVertexId() == end)
				break ;
			tmp = tmp->GetNextVertex();
		}
	}
	ReconstructRoute(routTrack, start, end);
}


void	Graph::ReconstructRoute(std::list<std::pair<int, int>> &rout, int start, int end)
{
	std::list<int> street;
	int cur;
	street.push_front(rout.back().second);
	street.push_front(rout.back().first);
	cur = rout.back().first;
	rout.pop_back();
	
	while (!rout.empty())
	{
		if (rout.back().second == cur)
		{
			cur = rout.back().first;
			street.push_front(cur);
		}
		rout.pop_back();
	}
	for (int v : street)
		std::cout << v << "  ";
	std::cout << std::endl;
}
