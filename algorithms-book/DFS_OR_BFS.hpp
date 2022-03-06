#ifndef __DFS_OR_BFS__
#define __DFS_OR_BFS__

#include "Graph-Api.hpp"
#include <list>
#include <functional>

class DFS_OR_BFS : public Graph
{
	public:
		explicit DFS_OR_BFS(std::fstream &file);
		void	operator()(const std::function<void(int)> &excute, bool = true, int = 0);
	private:
		void				Add_Neghibors_of(int index, std::list<int> &list);
		
		std::vector<bool>	visited;
};


#endif
