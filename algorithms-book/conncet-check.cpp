#include "conncet-check.hpp"

ConnectCheck::ConnectCheck(std::fstream &file) : Graph(file) , visited(number_of_vertxs, false)
{
}


void	ConnectCheck::operator()(std::vector<std::vector<int>> &res)
{
	size_t size = _graph.size();
	int index = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (not visited[i] and _graph[i].size())
		{
			res.push_back(std::vector<int>());
			simple_dfs(i, res[index]);
			++index;
		}
	}
}

void	ConnectCheck::simple_dfs(int start, std::vector<int> &res)
{
	int tmp;
	visited[start] = true;
	tmp_stack.push(start);

	while (not tmp_stack.empty())
	{
		tmp = tmp_stack.top();
		res.push_back(tmp);
		tmp_stack.pop();
		for (auto vertex : get_neighbors(tmp))
		{
			if (not visited[vertex])
			{
				visited[vertex] = true;
				tmp_stack.push(vertex);
			}
		}
	}
}
