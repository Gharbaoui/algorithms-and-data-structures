#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <stdlib.h>

struct Gen
{
	Gen(int d)
	{
		srand(0);
		dev = d;
	}
	std::pair<int, bool> operator()()
	{
		return {rand() % dev, false};
	}
	int dev;
};


bool	are_sets_disjoint(const std::vector<std::pair<int, bool>> &set1, decltype(set1) set2)
{
	std::unordered_map<int, bool>	hash(set1.begin(), set1.end()); // linear time

	for (auto &v2 : set2) // linear time
	{
		if (!hash.insert(v2).second)
			return false;
	}
	return true;

	//total is O(nm) where n is |set1| m |set2|
}


int main()
{

	int s1, s2;
	std::cout << "enter size of set 1: ";
	std::cin >> s1;
	std::cout << "enter size of set 2: ";
	std::cin >> s2;
	std::vector<std::pair<int, bool>>	set1(s1), set2(s2);

	std::generate(set1.begin(), set1.end(), Gen(10));
	std::generate(set2.begin(), set2.end(), Gen(100));
	
	for (auto& v : set1)
		std::cout << v.first << " ";
	std::cout << "\n";
	for (auto& v : set2)
		std::cout << v.first << " ";
	std::cout << "\n";

	std::cout << are_sets_disjoint(set1, set2);

}
