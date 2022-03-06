#ifndef __GRAPH_API__
#define __GRAPH_API__

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>

// adjacency based implmentation that reads from file
// format of file 
/*
 * i expect vertecs to bo from 0 to N-1 BEC i will use vector inside so vertex will be placed depending on it's number for example (0 9) will go to vector[0] and push 9
 * n1 represent number of lines in file
 * v w ==> and this lines will have vertix connetions 
 */
/*
 * here's example of file
 * 4
 * 0 3
 * 3 2
 * 1 4
 * 4 0
 */
class Graph
{
	public:
		explicit Graph(std::fstream &file, bool = false);
		friend std::ostream&	operator<<(std::ostream &os, const Graph &g);
		void					display_neighbors_of(int vertex);
		int						get_number_of_edges() const;
		int						get_number_of_vertixs() const;
		std::vector<int>		&get_neighbors(int index);
		int						degree_of(int) const;
		int						max_degree_of_graph() const;
		void							insert(const std::pair<int, int> &edge);
	protected:
		bool							is_directed;
		size_t							number_of_vertxs;
		size_t							number_of_edges;
		std::vector<std::vector<int>>	_graph;
};

#endif
