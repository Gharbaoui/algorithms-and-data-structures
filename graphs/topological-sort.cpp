#include "Graph.hpp"

void	Graph::TopSort(int start)
{
	InitArrsBool(MX_VERTEX);
	Vertex *tmp;
	int cur;
	std::list<int>	dfs_stack;
	std::list<int>	res;

	dfs_stack.push_back(start);

	while (!dfs_stack.empty())
	{
		cur = dfs_stack.back();
		tmp = apVertices[cur];
		if (IsAllProccessed(cur))
		{
			dfs_stack.pop_back();
			res.push_front(cur);
			aProccessed[cur] = true;
			tmp = NULL;
		}

		while (tmp)
		{
			if (!aProccessed[tmp->GetVertexId()])
			{
				dfs_stack.push_back(tmp->GetVertexId());
				break ;
			}
			tmp = tmp->GetNextVertex();
		}
	}

	for (int v : res)
		std::cout << v << " , ";
	std::cout << std::endl;
}


bool	Graph::IsAllProccessed(int index) const
{
	Vertex	*tmp = apVertices[index];
	while (tmp)
	{
		if (!aProccessed[tmp->GetVertexId()])
			return false;
		tmp = tmp->GetNextVertex();
	}
	return true;
}
