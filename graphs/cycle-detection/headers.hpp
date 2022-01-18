#ifndef __HEADERS__
#define __HEADERS__
#include <iostream>
#include <vector>
#include <set>
#include <list>

struct VertexInfo
{
	bool	operator<(const VertexInfo &rhs) const
	{
		return (id < rhs.id);
	}
	int id;
	mutable bool status; // status false means visited status true means proccessed
};

int8_t	CheckIfAllNeiProccessedAndAddNeiIfNot(const std::vector<std::vector<int>> &edge_list,
 std::list<int> &dfs_stack, std::set<VertexInfo> &VertexStatus);
int8_t	VertexInfoInSet(int cur, std::set<VertexInfo> &VertexStatus);
bool	DfsCycleDetection(std::vector<std::vector<int>> &edge_list);

#endif
