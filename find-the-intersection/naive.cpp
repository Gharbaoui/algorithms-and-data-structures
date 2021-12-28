#include <iostream>
#include <vector>
#include <algorithm>

void	naive_inter(const std::vector<int> &s1, std::vector<int> &s2);
class Unique{
	public:
		int	operator()()
		{
			return rand() % 253;
		}
};

int main()
{
	srand(time (NULL));
	std::vector<int> set1(5 + rand() % 10);
	std::vector<int> set2(5 + rand() % 20);

	std::generate(set1.begin(), set1.end(), Unique());
	std::generate(set2.begin(), set2.end(), Unique());
	std::cout << "SET1" << std::endl;
	for (int v : set1)
		std::cout << v << ", ";
	std::cout << std::endl;
	std::cout << "SET2" << std::endl;
	for (int v : set2)
		std::cout << v << ", ";
	std::cout << std::endl;
	set1.push_back(1000); // maybe genrate does not give intersects between set1 and set2 so i force at least one here
	set2.push_back(1000);
	
	naive_inter(set1, set2);
}

void	naive_inter(const std::vector<int> &set1, std::vector<int> &set2)
{
	for (int v1 : set1) // iter set1.size() times
	{
		for (int v2 : set2) // iter size2.size() times
		{
			if (v1 == v2)
			{
				std::cout << v1 << ", ";
				break ;
			}
		}
	}
	std::cout << std::endl;

	// so complexity is size1 * size2 which is bad
}
