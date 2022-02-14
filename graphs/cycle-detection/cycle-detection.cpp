#include "headers.hpp"

int	main()
{
	std::vector<std::vector<int>> v{
		/*{1, 6},
		{3, 1},
		{8, 1},
		{3 , 8},
		{1 , 2},
		{8 , 4},
		{3 , 4},
		{2 , 6},
		{6 , 5},
		{2 , 5},
		{4 , 5},
		{4 , 7},
		{5 , 7}*/
		{0 , 3},
		{0 , 2},
		{3 , 2}
		//{3 , 0},
	//	{4 , 2}
	};


	std::cout << DfsCycleDetection(v) << std::endl;
}
