#include <iostream>
#include "displayer.hpp"
#include "DFS_OR_BFS.hpp"
#include "path-finding.hpp"
#include "conncet-check.hpp"

int main(int argc, char **argv)
{
	std::fstream file;
	std::vector<std::vector<int>> res;
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


	ConnectCheck c(file);


	c(res);


	std::cout << res;



	std::cout << "directed graph\n";
	Graph gd(file, true);


	std::cout << gd;


}
