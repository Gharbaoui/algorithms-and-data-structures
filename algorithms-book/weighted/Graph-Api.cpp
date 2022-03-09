#include "Graph-Api.hpp"

Graph::Graph(std::fstream &gr_info, bool dir)
{
	/*
	 * i'm not checking on file so it better be valid
	 * should be there no empty lines
	 */
	std::map<int, char> mp;
	int tmp;
	int v1, v2, w;
	is_directed = dir;
	number_of_edges = 0;
	std::string str(100, 0);
	
	gr_info.getline(const_cast<char *>(str.c_str()), 100);
	std::remove_if (str.begin(), str.end(), [] (unsigned char c){
		return std::isspace(c);		
	});

	
	number_of_edges = std::stoi(str);
	if (is_directed)
		_graph.resize(number_of_edges + 1);
	else
		_graph.resize((number_of_edges * 2) + 1);

	for (size_t i = 0; i < number_of_edges; ++i)
	{
		gr_info.getline(const_cast<char *>(str.c_str()), 100);
		if (gr_info.gcount() == 0)
			break ;
		tmp = str.find_first_of (" ");
		const_cast<char *>(str.c_str())[tmp] = 0;

		v1 = std::stoi(str);
		v2 = std::stoi(str.c_str() + tmp + 1);
		tmp = str.find_first_of(" ", tmp + 1);
		tmp = str.find_first_not_of(" ", tmp);
		w = std::stoi(str.c_str() + tmp);
		this->insert(v1, {v2, w});
		mp.insert({v1, 'c'});
		mp.insert({v2, 'c'});
	}
	gr_info.seekg(0);
	number_of_vertxs = mp.size();
	_dists.clear();
	_dists.resize(number_of_vertxs);
}

void	Graph::insert(int start, const std::pair<int, int> &edge)
{
	// second pair represent weight
	_graph[start].push_back(edge);
	if (!is_directed)
		_graph[edge.first].push_back({start, edge.second});
}

std::vector<std::pair<int, int>>		&Graph::get_neighbors(int index)
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
		if (vect.size())
		{
			os << "\033[32m[" << index << "] -> \033[0m";
			for (i = 0; i < vect.size() - 1; ++i)
				os << "[" << vect[i].first << ", " << vect[i].second << "] , ";
			os << "[" << vect[i].first << ", " << vect[i].second << "]";
			os << "\n";
		}
		++index;
	}
	os << "number of vertces: " << g.number_of_vertxs << "  number of edges: " << g.number_of_edges << "\n";
	return os;
}


void	Graph::bellman_ford(const std::function<void (std::pair<int, int>)> &excute, int start)
{
	_dists.assign(number_of_vertxs, 1000);
	_dists[start] = 0;
	
	unsigned int cur_weight;
	unsigned int tmp_dist;

	for (size_t i = 0; i < number_of_vertxs; ++i)
	{
		if (not _graph[i].size())
			continue ;
		cur_weight = _dists[i];
		for (auto &pair : _graph[i])
		{
			tmp_dist = cur_weight + pair.second;
			if (tmp_dist < _dists[pair.first])
			{
				_dists[pair.first] = tmp_dist;
			}
		}
	}

	for (size_t i = 0; i < number_of_vertxs; ++i)
	{
		excute({i, _dists[i]});
	}
}
