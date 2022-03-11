#include <iostream>
#include <vector>
#include <limits>

/**/


class Solution {
	public:
		int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
			std::vector<int>	stops(n, max);
			std::vector<int>	tmpStops(n, -1);
			std::vector<int>	dists(n, max);
			std::vector<int>	real_dists(n, max);
			dists[src] = 0;
			stops[src] = 0;
			stops[dst] = -1;
			tmpStops[src] = 0;
			bool changed;
			int tmpdist;

			++k;
			for (size_t i = 0; i < n; ++i)
			{
				changed = false;
				for (auto &E : flights)
				{
					if (dists[E[0]] != max)
					{
						// means that we know what it takes to get to the start of this edge
						tmpdist = dists[E[0]] + E[2];
						if (tmpdist < dists[E[1]] && tmpStops[E[0]] < k)
						{
							dists[E[1]] = tmpdist;
							tmpStops[E[1]] = tmpStops[E[0]] + 1;
							changed = true;
						}
					}
				}
				
				if (changed)
				{
					if (tmpStops[dst] <= k){
						stops = tmpStops;
						real_dists = dists;
					}
				}else
					break ;
			}
			if (stops[dst] != -1)
			{
				std::cout << stops[dst] << "\n";
				return real_dists[dst];
			}
			return -1;
		}
	private:
		int max = std::numeric_limits<int>::max();
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> graph{{0,1,1},{0,2,5},{1,2,1},{2,3,1}};

	std::cout << s.findCheapestPrice(4, graph, 0, 3, 1) << "\n";
}
