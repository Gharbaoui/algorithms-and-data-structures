#ifndef __PATH_FINDING__
#define __PATH_FINDING__
#include "DFS_OR_BFS.hpp"
#include <algorithm>
class PathFinding : public DFS_OR_BFS
{
	public:
		explicit PathFinding(std::fstream &file);
		void	operator()(int start, int end, const std::function<void (int)> &excute) noexcept;
	private:
		std::vector<int>	bfs_path;
		std::vector<int>	path;
};


#endif
