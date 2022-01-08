#include <iostream>
#include <vector>
#include "Graph.hpp"

int main()
{
	Graph graph(7, 9);
	std::vector<std::pair<int, int> > ver{
		std::make_pair(0, 2),
		std::make_pair(0, 1),
		std::make_pair(1, 3),
		std::make_pair(1, 4),
		std::make_pair(2, 3),
		std::make_pair(3, 4),
		std::make_pair(4, 5),
		std::make_pair(4, 6),
		std::make_pair(5, 6)
	};	
	graph.Insert(ver.begin(), ver.end());

	graph.display();
	graph.DepthFirstTraversal(0, [] (int v) {
		std::cout << v << "  ";
	});
	int count = 0;
	graph.BreathFirstTraversal(0, [&] (int v) {
		++count;
		std::cout << v << "  ";
	});
	std::cout << count << std::endl;
}
