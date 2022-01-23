#include "solution.hpp"

int	main()
{
	std::vector<std::vector<int>> edge{
		{0, 1},
		{0, 3},
		{1, 2},
		{3, 2},
		{2, 4},
		{4, 5},
		{5, 6},
		{5, 8},
		{8, 7},
		{6, 7}
	};

	Solution s(edge, 9);

	s.Display();

	s.PrintBridges();
}
