#include <iostream>
#include "Graph-Api.hpp"


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

	Graph g(file, true);
	std::cout << g;


	g.bellman_ford([] (std::pair<int, std::vector<int>> pair)
	{
		std::vector <int> &path = pair.second;
		for (auto val : path)
			std::cout << val << " ";
		std::cout << " | total distance is: " << pair.first << "\n";
	}, 1);


}
