#include <iostream>
#include <vector>
#include "Graph.hpp"

int main()
{
	Graph graph(6, 6, true);
	std::vector<std::pair<int, int> > ver{
		std::make_pair(0, 1),
		std::make_pair(0, 3),
		std::make_pair(1, 3),
		std::make_pair(1, 2),
		std::make_pair(2, 3),
		std::make_pair(2, 4),
		std::make_pair(2, 5),
		std::make_pair(3, 5),
		std::make_pair(3, 4),
		std::make_pair(4, 5),
	};	
	graph.Insert(ver.begin(), ver.end());

	graph.display();
	graph.TopSort(0);
}
