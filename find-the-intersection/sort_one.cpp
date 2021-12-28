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

bool	found(int v, const std::vector<int> &set);
void	sort_one_inter(std::vector<int> &set1, std::vector<int> &set2)
{
	int size1(set1.size());
	int size2(set2.size());

	if (size1 < size2)
	{
		std::sort(set1.begin(), set1.end());
		for (int v : set2)
		{
			if (found(v, set1))
				std::cout << v << " ";
		}
	}
	else
	{
		std::sort (set2.begin(), set2.end());
		for (int v : set1)
			if (found(v, set2))
				std::cout << v << ", ";
	}
	std::cout << std::endl;
}


bool	found(int v, const std::vector<int> &set)
{
	int mid;
	int start = 0;
	int end = set.size() - 1;

	while (end >= start)
	{
		mid = start + (end - start)/2;
		if (set[mid] == v)
			return true;
		else if (v > set[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
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

	sort_one_inter(set1, set2);

	
}
