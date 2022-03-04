#include <iostream>
#include "disjoint.hpp"
void	InitSets(std::vector<OneSet<int>> &sets);

template <typename T>
std::ostream&	operator<<(std::ostream &os, std::vector<OneSet<T>> &sts)
{
	for (auto &v : sts)
	{
		os << "repre: " << v.getRepresentive() << " ";
		for (auto val : v.getVect())
			os << val << " ";
		os << "\n";
	}
	return os;
}

int main()
{
	int numsets;
	std::cout << "enter a number of sets: ";
	std::cin >> numsets;
	std::vector<OneSet<int>> sets(numsets);
	InitSets(sets);
	std::cout << sets;

	DisjointSet<int> ds(sets, -1);
	std::cout << ds << "\n";

	int x, y;
	int index;
	index = rand() % sets.size();
	x = sets[index][rand () % sets[index].getVect().size()];
	index = rand() % sets.size();
	y = sets[index][rand () % sets[index].getVect().size()];

	std::cout << "\nX: " << x << " Y: " << y << "\n";
	ds.unite(x, y);
	std::cout << ds << "\n";
}

void	InitSets(std::vector<OneSet<int>> &sets)
{
	srand(time(nullptr));
	int numsets = sets.size();
	int numelm;

	for (size_t i = 0; i < numsets; ++i)
	{
		numelm = rand() % 5;
		for (size_t j = 0; j < numelm; ++j)
			sets[i].insert(rand() % 100);
		sets[i].insert(rand() % 100, true);
	}
}
