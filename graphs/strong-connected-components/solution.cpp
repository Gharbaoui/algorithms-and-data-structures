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
		graph[edges[i][0]].push_back(edges[i][1]);
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

void	Solution::PrintStrongConnectedComponents()
{
	bool	done[nvertices];
	bool	visited[nvertices];

	std::fill_n(done, nvertices, false);
	
	for (int i = 0; i < nvertices; ++i)
	{
		if (!done[i])
		{
			if (graph[i].size()) {
				std::fill_n(visited, nvertices, false);
				// using dfs or bfs (i) will check if neighbors of i aka graph[i]
				// are able to go back to (i)
				DFSReachTraget(i, visited, done);
				std::cout << std::endl;
			}
		}
	}
}


void	Solution::DFSReachTraget(int index, bool *visited, bool *done)
{
	int cur;
	dfs_stack.push_back(index);
	visited[index] = true;

	while (!dfs_stack.empty())
	{
		cur = dfs_stack.back();
		dfs_stack.pop_back();
		if (cur == index || FromCurToIndex(cur, index))
		{
			std::cout << cur << ", ";
			done[cur] = true;
			
		}
		for (int v : graph[cur])
		{
			if (!visited[v])
			{
				dfs_stack.push_back(v);
				visited[v] = true;
			}
		}
	}
}

bool	Solution::FromCurToIndex(int start, int target)
{
	int cur;
	bool	visited[nvertices];
	std::fill_n(visited, nvertices, false);
	tmp_stack.push_back(start);
	visited[start] = true;

	while (!tmp_stack.empty())
	{
		cur = tmp_stack.back();
		tmp_stack.pop_back();
		for (int v : graph[cur])
		{
			if (!visited[v])
			{
				if (v != target)
					tmp_stack.push_back(v);
				else
				{
					tmp_stack.clear();
					return true;
				}
				visited[v] = true;
			}
		}
	}
	return false;
}
