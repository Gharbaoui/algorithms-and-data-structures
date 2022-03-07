#include "path-finding.hpp"

PathFinding::PathFinding(std::fstream &file) : DFS_OR_BFS(file)
{
}

void	PathFinding::operator()(int start, int end, const std::function<void (int)> &excute) noexcept
{
	// brute force solutuin in other words it's bad solution
	try
	{
		DFS_OR_BFS::operator()(
		[=](int vertex)
		{
			bfs_path.push_back(vertex);
			if (vertex == end)
				throw true;
		}
		, false, start);
	}catch (...)
	{
		decltype(bfs_path.rbegin()) tmp_itr;
		for (auto iter = bfs_path.rbegin(); iter != bfs_path.rend();)
		{
			path.push_back(*iter);
			if (iter + 1 == bfs_path.rend())
				break ;
			for (auto it = iter + 1; it != bfs_path.rend(); ++it)
			{
				for (auto val : get_neighbors(*iter))
				{
					if (val == *it)
						tmp_itr = it;
				}
			}
			iter = tmp_itr;
		}

		for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
		{
			excute(*iter);
		}
	}
}
