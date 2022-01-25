#include "solution.hpp"

int	main()
{
	std::vector<std::vector<int>> edge{
		{7, 2},
		{2, 6},
		{6, 3},
		{3, 2},
		{6, 7},
		{3, 1},
		{1, 5},
		{5, 1},
		{6, 4},
		{4, 5}
	};

	Solution s(edge, 8);

	s.Display();
	s.PrintStrongConnectedComponents();
}
