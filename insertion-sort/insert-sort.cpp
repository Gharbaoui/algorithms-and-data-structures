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
	int smv;
	int smi;
	for (int i = 0; i <= size - 2; ++i)
	{
		smv = A[i];
		smi = i;
		for (int j = i + 1; j <= size - 1; ++j)
		{
			if (smv > A[j])
			{
				smv = A[j];
				smi = j;
			}
		}
		std::swap(A[i], A[smi]);
	}
}

/*
 	complexity
	outer loop will run n times where n = size - 2
	stuff inside it at lines 34 35 44 are constants O(1)
	and the loop that dependent on i
	inner loop will run at (n - j) times ignoring 1 just for simplfication
	at first will run (n + O(1)) times
	at second will run (n - 1 + O(1)) times
	at third will run (n - 2 + O(1)) times
	.
	.
	.
	at end will run (0 + O(1))
	we could write total will be
	(n + O(1)) + (n - 1 + O(1)) + . . . O(1)
	reorgnize
	(0 + 1 + 2 + 3 + . . . n) + ((O(1) + O(1) + O(1) + ...)n times)
	first part will be 
	n*(n-1)/2
	second part will be 
	n*O(1)
	n^2 + n
	so O(n^2) maybe i skip some steps unexplained
 */

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
