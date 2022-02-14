#include "solution.hpp"

Solution::Solution(const std::vector<std::vector<int>> &edges, int nvertices)
{
	ConstructeFromList(edges, nvertices);
}


void	Solution::ConstructeFromList(const std::vector<std::vector<int>> &edges, int nvertices)
{
	int size(edges.size());
	this->nvertices = nvertices;
	graph.clear();
	graph.assign(nvertices, {});
	for (int i = 0; i < size; ++i)
	{
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]); // if you want directed graph remove this line
	}
}


void	Solution::Display() const
{

	for (int i = 0; i < nvertices; ++i)
	{
		if (graph[i].size())
			std::cout << "\033[1;31m{" << i << "}\033[0m";
		else
			continue ;
		for (int v : graph[i])
			std::cout << " -> " << v;
		std::cout << std::endl;
	}
}


void	InitBools(bool *visited, int size)
{
	for (int i = 0; i < size; ++i)
		visited[i] = false;
}

void	Solution::PrintBridges() const
{
	bool	visited[nvertices];
	std::set<std::pair<int, int>> bridges;

	for (int i = 0; i < nvertices; ++i)
	{
		for (int v : graph[i])
		{
			InitBools(visited, nvertices);
			if (DFS_check(visited, {i, v}))
				if (bridges.count({v, i}) == 0)
					bridges.insert({i, v});
		}
	}

	for (std::set<std::pair<int, int>>::iterator i = bridges.begin(); i != bridges.end(); ++i)
	{
		std::cout << "{" << i->first << ", " << i->second << "}" << std::endl;
	}
}

bool	Solution::DFS_check(bool *visited, std::pair<int, int> edge) const
{
	int tmp;
	std::list<int> dfs_stack;
	tmp = edge.first;
	dfs_stack.push_back(tmp);
	visited[tmp] = true;

	while (!dfs_stack.empty())
	{
		tmp = dfs_stack.back();
		dfs_stack.pop_back();
		for (int v : graph[tmp])
		{
			if (!visited[v])
			{
				if (v != edge.second)
				{
					visited[v] = true;
					dfs_stack.push_back(v);
				} else if (tmp != edge.first)
					return false;
			}
		}
	}
	return true;
}
