#include <iostream>
#include <utility>

void	selection_sort(int *arr, int size);

int main()
{
	int	size;
	std::cout << "enter size of array: ";
	std::cin >> size;
	int	arr[size];
	srand(time (NULL));
	std::cout << "Before\n";
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 1000;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After\n";
	selection_sort(arr, size);
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void	selection_sort(int *arr, int size)
{
	int	min;

	for (int i = 0; i < size; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; ++j)
			if (arr[j] < arr[min])
				min = j;
		std::swap(arr[i], arr[min]);
	}
}

