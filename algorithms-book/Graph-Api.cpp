#include "Graph-Api.hpp"

Graph::Graph(std::fstream &gr_info, bool dir)
{
	/*
	 * i'm not checking on file so it better be valid
	 * should be there no empty lines
	 */
	std::map<int, char> mp;
	int tmp;
	int v1, v2;
	is_directed = dir;
	number_of_edges = 0;
	std::string str(100, 0);
	
	gr_info.getline(const_cast<char *>(str.c_str()), 100);
	std::remove_if (str.begin(), str.end(), [] (unsigned char c){
		return std::isspace(c);		
	});

	
	number_of_edges = std::stoi(str);
	if (!is_directed)
		_graph.resize(number_of_edges);
	else
		_graph.resize(number_of_edges * 2);
	for (size_t i = 0; i < number_of_edges; ++i)
	{
		gr_info.getline(const_cast<char *>(str.c_str()), 100);
		if (gr_info.gcount() == 0)
			break ;
		tmp = str.find_first_of (" ");
		const_cast<char *>(str.c_str())[tmp] = 0;

		v1 = std::stoi(str);
		v2 = std::stoi(str.c_str() + tmp + 1);
		this->insert({v1, v2});
		mp.insert({v1, 'c'});
		mp.insert({v2, 'c'});
	}
	gr_info.seekg(0);
	number_of_vertxs = mp.size();
}

void	Graph::insert(const std::pair<int, int> &edge)
{
	_graph[edge.first].push_back(edge.second);
	if (!is_directed)
		_graph[edge.second].push_back(edge.first);
}

std::vector<int>		&Graph::get_neighbors(int index)
{
	return _graph[index];
}

int						Graph::max_degree_of_graph() const
{
	unsigned int max = 0;
	for (auto &vect : _graph)
	{
		if (max < vect.size())
			max = vect.size();
	}
	return max;
}

int						Graph::degree_of(int index) const
{
	return _graph[index].size();
}

void					Graph::display_neighbors_of(int vertex)
{
	size_t i;
	for (i = 0; i < _graph[vertex].size() - 1; ++i)
		std::cout << _graph[vertex][i] << ", ";
	std::cout << _graph[vertex][i] << "\n";

}

int						Graph::get_number_of_edges() const
{
	return number_of_edges;
}

int						Graph::get_number_of_vertixs() const
{
	return number_of_vertxs;
}

std::ostream&	operator<<(std::ostream &os, const Graph &g)
{
	int index = 0;
	size_t i;
	for (auto &vect : g._graph)
	{
		if (vect.size() == 0)
			continue ;
		os << "\033[32m[" << index++ << "] -> \033[0m";
		for (i = 0; i < vect.size() - 1; ++i)
			os << vect[i] << ", ";
		os << vect[i];
		os << "\n";
	}
	os << "number of vertces: " << g.number_of_vertxs << "  number of edges: " << g.number_of_edges << "\n";
	return os;
}
