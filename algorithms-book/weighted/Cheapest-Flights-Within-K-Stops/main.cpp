#include <iostream>
#include <vector>
#include <limits>

/**/
class Solution {
	public:
		Solution() {
			result = {max, max};
			max = std::numeric_limits<int>::max();
		}
		int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
			costs.resize(n, max);
			tmp_costs.resize(n, max);

			costs[src] = 0;

			for (i = 0; i <= k; ++i)
			{
				for (auto &edge : flights)
				{
					if (costs[edge[0]] != max)
					{
						tmp_cost = costs[edge[0]] + edge[2];
						if (tmp_cost < tmp_costs[edge[1]])
							tmp_costs[edge[1]] = tmp_cost;
					}
                }
			    costs = tmp_costs;

            }
			if (costs[dst] != max)
				return costs[dst];
			return -1;
		}
	private:
		std::vector<int>	costs, tmp_costs;
		int	*cur;
		unsigned short i;
		unsigned short count;
		unsigned short tmp_cost;
		std::pair<unsigned short, unsigned short> result;
		int max;
};


int main()
{
	Solution s;
	std::vector<std::vector<int>> graph {{0,3,7},{4,5,3},{6,4,8},{2,0,10},{6,5,6},{1,2,2},{2,5,9},{2,6,8},{3,6,3},{4,0,10},{4,6,8},{5,2,6},{1,4,3},{4,1,6},{0,5,10},{3,1,5},{4,3,1},{5,4,10},{0,1,6}};

	std::cout << s.findCheapestPrice(7, graph, 2, 4, 1) << "\n";
}
