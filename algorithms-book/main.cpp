#include <iostream>
#include "DFS_OR_BFS.hpp"
#include "path-finding.hpp"

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

	PathFinding path(file);

	path(0, 4, [](int vertex)
	{
		std::cout << vertex << " ";
	});


}
