#include "DFS_OR_BFS.hpp"


DFS_OR_BFS::DFS_OR_BFS(std::fstream &file) : 
Graph(file) , 
visited(number_of_vertxs, false)
{}


void	DFS_OR_BFS::operator()(const std::function<void(int)> &excute, bool is_dfs, int start)
{
	// BY THIS IMPLMENTATION DOES NOT LOOP OVER _GRAPH vector which means that if graph has multiple connected compnents i will expolre only what is connected to start node
	//
	std::list<int>	list;
	int tmp;
	list.push_back(start);
	visited[start] = true;
	while (not list.empty()) // at max will run N where N is number of vertexs
	{
		if (is_dfs)
		{
			tmp = list.back();
			list.pop_back();
		}
		else
		{
			tmp = list.front();
			list.pop_front();
		}
		excute(tmp);
		Add_Neghibors_of(tmp, list);
	}
	visited.assign(number_of_vertxs, false);
	// total complexity is n*(n-1)
	// so O(N^2)
}


void	DFS_OR_BFS::Add_Neghibors_of(int index, std::list<int> &list)
{
	for (auto v : _graph[index]) // at max will run N-1 here i'm assuming that each vertx is connected to other vertix
	{
		if (not visited[v])
		{
			visited[v] = true;
			list.push_back(v);
		}
	}
}
