#include "graph.hpp"
#include <utility>
#include <vector>

int main()
{
	std::vector<std::pair<int, int> > v {
		std::make_pair(3, 4),
		std::make_pair(0, 1),  
		std::make_pair(0, 2),
		std::make_pair(0, 10),
		std::make_pair(2, 10),
		std::make_pair(1, 2),
		std::make_pair(1, 3),
		std::make_pair(1, 4),
		std::make_pair(3, 5),
		std::make_pair(3, 14),
		std::make_pair(5, 14),
		std::make_pair(5, 6),
		std::make_pair(5, 7),
		std::make_pair(7, 8),
		std::make_pair(8, 9),
		std::make_pair(5, 8)
	};
	Graph g;
	int num_of_edges;
	int num_of_v;
	int x, y;
/*	std::cout << "please enter number of edges: ";
	std::cin >> num_of_edges;
	std::cout << "please enter number of vertices: ";
	std::cin >> num_of_v;
	g.setNumberOfVerteces(num_of_v);*/

	for (int i = 0; i < v.size(); ++i)
	{
	/*	std::cout << "Enter a node and what is connecting to: ";
		std::cin >> x;
		std::cin >> y;*/
		
		g.insert(v[i].first, v[i].second);
	}

	g.shortes_path(0, 5);
	
}
