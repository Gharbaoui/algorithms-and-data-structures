#include <iostream>
#include <vector>


void	merg_sort(std::vector<int> &arr, int start, int end);
void	merg_sorted(std::vector<int> &v, int start, int mid, int end);
int main()
{
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	std::vector<int> v(size);
	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		v[i] = rand() % 100;
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;

	merg_sort(v, 0, size - 1);
	for (int i = 0; i < size; ++i)
		std::cout << v[i] << ", ";
	std::cout << std::endl;
}

void	merg_sort(std::vector<int> &v, int start, int end)
{
	int mid;
	if (end > start)
	{
		mid = start + (end - start)/2;
		merg_sort(v, 0, mid);
		merg_sort(v, mid+1, end);
		merg_sorted(v, start, mid, end);
	}
}

void	merg_sorted(std::vector<int> &v, int start, int mid, int end)
{
	std::vector<int> tmp(end - start + 1);
	int	k = 0;
	int	i;
	int	j;

	for (i = start, j = mid + 1; i <= mid && j <= end;)
	{
		if (v[i] < v[j])
		{
			tmp[k] = v[i];
			++i;
		}
		else
		{
			tmp[k] = v[j];
			++j;
		}
		++k;
	}
	while (i <= mid)
		tmp[k++] = v[i++];
	while (j <= end)
		tmp[k++] = v[j++];
	for (int i = 0; start + i<= end; ++i)
		v[start + i] = tmp[i];
}
