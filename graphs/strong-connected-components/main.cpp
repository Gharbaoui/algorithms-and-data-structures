#include "solution.hpp"

int	main()
{
	std::vector<std::vector<int>> edge{
		{1, 3},
		{2, 1},
		{3, 2},
		{4, 3},
		{5, 4},
		{6, 5},
		{5, 7},
		{7, 6}
	};

	Solution s(edge, 8);

	s.Display();

	s.kosarajuAlgo();
}
