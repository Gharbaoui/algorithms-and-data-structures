#include "headers.hpp"

class Solution {
	private:
		std::vector<std::vector<int>> aGraphList;
		std::list<int>	dfs_stack;
		int TOTAL;
	public:
		bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
			if (prerequisites.size() < 2)
				return true;
			bool	visted[numCourses], onStack[numCourses], done[numCourses];
			TOTAL = numCourses;
			InitGraphList(prerequisites, numCourses);
			InitBools(visted, onStack);
			InitDone(done);
			for (int i = 0; i < numCourses; ++i)
			{
				if (!done[i])
				{
					if (IsCycle(i, visted, onStack, done))
					{
						return false;
					}
					InitBools(visted, onStack);
				}
			}
			return true;
		}
	private:
		bool	IsCycle(int index, bool *visit, bool *onStack, bool *done)
		{
			int tmp;
			dfs_stack.push_back(index);
			visit[index] = true;
			
			while (!dfs_stack.empty())
			{
				tmp = dfs_stack.back();
				onStack[tmp] = true;
				if (AllNeihDone(tmp, done))
				{
					done[tmp] = true;
					dfs_stack.pop_back();
					onStack[tmp] = false;
					continue ;
				}
				if (AddUnvisitedNeighbors(tmp, visit, onStack, done))
					return true;
			}
			return false;
		}

		bool	AddUnvisitedNeighbors(int index, bool *visit, bool *onStack, bool *done)
		{
			// if true is returned means that thers cycle
			std::vector<int> &vec = aGraphList[index];
			int state(0);
			for (int i = 0; i < vec.size(); ++i)
			{
				if (!done[vec[i]])
				{
					if (!visit[vec[i]])
					{
						state = 1;
						visit[vec[i]] = true;
						dfs_stack.push_back(vec[i]);
					}else if (onStack[vec[i]])
						return true;
				}
			}
			if (!state) {
				onStack[dfs_stack.back()] = false;
				dfs_stack.pop_back();
			}
			return false;
			
		}

		bool	AllNeihDone(int index, bool *done)
		{
			std::vector<int> &vec = aGraphList[index];
			for (int i = 0; i < vec.size(); ++i)
			{
				if (!done[vec[i]])
					return false;
			}
			return true;
		}
	
		void	InitBools(bool *arr1, bool *arr2)
		{
			for (int i = 0; i < TOTAL; ++i) {
				arr1[i] = false;
				arr2[i] = false;
			}
		}

		void	InitDone( bool *arr1)
		{
			for (int i = 0; i < TOTAL; ++i)
				arr1[i] = false;
		}
		void	InitGraphList(const std::vector<std::vector<int>> &prerequisites, int numCourses)
		{
			aGraphList.assign(numCourses, {});
			for (int i = 0; i < prerequisites.size(); ++i)
				aGraphList[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
};

