#include <iostream>
#include <vector>
#include <algorithm>



class Unique{
	public:
		int	operator()()
		{
			return rand() % 253;
		}
};


void	both_are_sorted(std::vector<int> &set1, std::vector<int> &set2)
{
	int set1_size = set1.size();
	int set2_size = set2.size();
	std::sort(set1.begin(), set1.end());
	std::sort(set2.begin(), set2.end());
	

	for (int i = 0, j = 0; (i < set1_size && j < set2_size);)
	{
		if (set1[i] < set2[j])
			++i;
		else if (set2[j] < set1[i])
			++j;
		else
		{
			std::cout << set1[i] << ", ";
			++i;
			++j;
		}
	}

	std::cout << std::endl;
}

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

	both_are_sorted(set1, set2);
	
}
