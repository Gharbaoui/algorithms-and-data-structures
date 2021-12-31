#include <iostream>
#include <vector>
#include <numeric>
#include <limits.h>


void	counting_sort(std::vector<int> &arr, int size);
int main()
{
	srand(time(NULL));
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	std::vector<int> v{101, 117, 110, 117, 102, 102, 111, 102, 100, 120};
	
	for (int i = 0; i < size; ++i)
	{
	//	v[i] = rand() % 50;
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;

	counting_sort(v, size);
}

void	counting_sort(std::vector<int> &arr, int size)
{
	int min, max;
	std::vector<int> new_arr(size); // new array that will be sorted
	std::vector<int> count, range;
	int		range_size;
	
	min = INT_MAX;
	max = INT_MIN;

	// this loop finds min and max in this array
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
		else if (arr[i] > max)
			max = arr[i];
	}
	// constructing the counting array
	range_size = max - min + 1;
	range.reserve(range_size);
	count.assign(range_size, 0);
	for (int i = 0; i < range_size; ++i) // make range in this loop
		range.push_back(min + i);
	for (int i = 0; i < size; ++i) // count from arr how much each elm is accourd and stored in count
		++count[arr[i] - min];
	for (int i = 1; i < range_size; ++i)
		count[i] += count[i - 1];

	int index;
	for (int i = 0; i < size; ++i)
	{
		index = --count[arr[i] - min];
		new_arr[index] = arr[i];
	}

	for (int v : new_arr)
		std::cout << v << " ";
	std::cout << std::endl;
}
