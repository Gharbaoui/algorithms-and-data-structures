#ifndef	__SOLUTION__
#define __SOLUTION__

#include <vector>
#include <list>
#include <set>
#include <utility>
#include <iostream>

class	Solution
{
	public:
		Solution(const std::vector<std::vector<int>> &edges, int);
		void	ConstructeFromList(const std::vector<std::vector<int>> &, int);
		void	Display() const;
		void	PrintBridges() const;
		bool	DFS_check(bool *, std::pair<int, int>) const;
	private:
		int nvertices;
		std::vector<std::vector<int>>	graph;
};



#endif
