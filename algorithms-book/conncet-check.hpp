#ifndef __CONNECT_CHECK__
#define __CONNECT_CHECK__

#include "Graph-Api.hpp"
#include <stack>
class	ConnectCheck : public Graph
{
	public:
		ConnectCheck(std::fstream &file);
		void	operator()(std::vector<std::vector<int>> &res);
	private:
		void	simple_dfs(int start, std::vector<int> &res);
		std::vector<bool>		visited;
		std::stack<int>			tmp_stack;
};


#endif
