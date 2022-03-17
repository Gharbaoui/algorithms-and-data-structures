#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include  <algorithm>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
	for (auto &val : v)
		os << val << " ";
	return os;
}

struct Gen
{
	Gen()
	{
		srand(time(0));
	}
	int	operator()()
	{
		return (rand() % 100) - (rand() % 50);
	}
};


void	insertion_sort(std::vector<int> &A, int size)
{
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; (j > 0 && A[j] < A[j - 1]) ; --j)
			std::swap(A[j], A[j - 1]);
}

int main()
{
	std::vector<int> arr(20);
	std::generate(arr.begin(), arr.end(), Gen());

	std::cout << arr << "\n";
	std::cout << "is sorted: " << std::is_sorted(arr.begin(), arr.end()) << "\n";

	insertion_sort(arr, arr.size());
	std::cout << arr << "\n";

	std::cout << "is sorted: " << std::is_sorted(arr.begin(), arr.end()) << "\n";
}
