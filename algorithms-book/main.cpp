#include <iostream>
#include "DFS_OR_BFS.hpp"

int main(int argc, char **argv)
{
	std::fstream file;
	if (argc > 1)
	{
		file.open(argv[1]);
	}
	else
	{
		std::cout << "defalut is graph.txt\n";
		file.open("graph.txt");
	}
	if (!file.is_open())
		return 12;

	Graph g(file);
	std::cout << g;

	// trying dfs
	DFS_OR_BFS	dfs_algo(file);

	dfs_algo([](int value)
	{
		std::cout << value << " ";
	});
	std::cout << "\n";
	dfs_algo([](int value)
	{
		std::cout << value << " ";
	}, false);

}
