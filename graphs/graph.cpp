#include "graph.hpp"


int main()
{
	Graph g;
	int num_of_v;
	int x, y;
	std::cout << "please enter number of vertices: ";
	std::cin >> num_of_v;

	for (int i = 0; i < num_of_v; ++i)
	{
		std::cout << "Enter a node and what is connecting to: ";
		std::cin >> x;
		std::cin >> y;
		g.insert(x, y);
	}


	g.display();
}
