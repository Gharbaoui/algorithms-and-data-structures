#include "headers.hpp"


bool	DfsCycleDetection(std::vector<std::vector<int>> &edge_list)
{
	int cur(edge_list[0][0]);
	int8_t status;
	std::set<VertexInfo>	VertexStatus;
	std::list<int>		dfs_stack;

	dfs_stack.push_back(cur);
	VertexStatus.insert({cur, false});

	while (!dfs_stack.empty())
	{
		status = CheckIfAllNeiProccessedAndAddNeiIfNot(edge_list, dfs_stack, VertexStatus);
		if (status == 0)
		{
			cur = dfs_stack.back();
			dfs_stack.pop_back(); // status 0 indactes that nothing was added to dfs__stack
			VertexStatus.find({cur, false})->status = true;
		}
		else if (status == -1)
			return true;
	}
	return false;
}


int8_t	CheckIfAllNeiProccessedAndAddNeiIfNot(const std::vector<std::vector<int>> &edge_list, std::list<int> &dfs_stack, std::set<VertexInfo> &VertexStatus)
{
	// will return -1 if we try to add neighbor that already marked as visted
	// will return 0 if all neighbors were proccessed before
	// will return 1 if we add unvisited vertex
	int size(edge_list.size());
	int cur(dfs_stack.back());
	int8_t	state;
	int8_t	status(0);

	for (int i = 0; i < size; ++i)
	{
		if (cur == edge_list[i][0])
		{
			state = VertexInfoInSet(edge_list[i][1], VertexStatus);
			if (state == 0)
			{
				dfs_stack.push_back(edge_list[i][1]);
				VertexStatus.insert({edge_list[i][1], false});
				status = 1;
			}
			else if (state == -1)
				return -1;
		}
	}
	return status;
}

int8_t	VertexInfoInSet(int cur, std::set<VertexInfo> &VertexStatus)
{
	// will return -1 if visted
	// will return 0 if does not exist
	// will return 1 if it was proccessed
	
	std::set<VertexInfo>::const_iterator	itr(VertexStatus.find({cur, false}));

	if (itr != VertexStatus.end() && itr->id == cur)
	{
		if (itr->status == true)
			return 1;
		return -1;
	}
	return 0;
}
