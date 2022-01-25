#ifndef	__SOLUTION__
#define __SOLUTION__

#include <vector>
#include <list>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>

class	Solution
{
	public:
		Solution(const std::vector<std::vector<int>> &edges, int);
		void	ConstructeFromList(const std::vector<std::vector<int>> &, int);
		void	Display() const;
		void	PrintStrongConnectedComponents();
		void	DFSReachTraget(int index, bool *visited, bool *done);
		bool	FromCurToIndex(int start, int target);
	private:
		std::list<int>	dfs_stack;
		std::list<int>	tmp_stack;
		int nvertices;
		std::vector<std::vector<int>>	graph;
};



#endif
