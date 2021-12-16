#include <iostream>
#include <utility>

void	insert_sort(int *arr, int size);

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
	insert_sort(arr, size);
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void	insert_sort(int *arr, int size)
{
	int	index(1);


	while (index < size)
	{
		for (int i = index; i > 0; --i)
			if (arr[i - 1] > arr[i])
				std::swap(arr[i], arr[i - 1]);
		++index;
	}
}
