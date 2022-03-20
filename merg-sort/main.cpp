#include <iostream>
#include <vector>


void combine(int start, int mid, int end, std::vector<int> &A)
{
	int TMP[end - start + 1];
	int k = 0;
	int i, j;
	for (i = start, j = mid + 1; (i <= mid && j <= end);)
	{
		if (A[i] < A[j])
		{
			TMP[k] = A[i];
			++i;
		}
		else
		{
			TMP[k] = A[j];
			++j;
		}
		++k;
	}
	while (j <= end)
		TMP[k++] = A[j++];
	while (i <= mid)
		TMP[k++] = A[i++];
	k = 0;
	for(i = start; i <= end; ++i, ++k)
		A[i] = TMP[k];
}

void merg_sort(int start, int end, std::vector<int> &A)
{
	int mid;
	if (end - start > 0)
	{
		mid = start + (end - start)/2;
		merg_sort(start, mid, A);
		merg_sort(mid+1, end, A);
		combine(start, mid, end, A);
	}
}

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

	merg_sort(0, size - 1, v);
	for (int i = 0; i < size; ++i)
		std::cout << v[i] << ", ";
	std::cout << std::endl;
}
