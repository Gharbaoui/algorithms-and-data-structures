#include "heap.hpp"

Heap::Heap(int cap)
{
	_arr.reserve(cap);
}

void	Heap::Insert(const TYPE &val)
{
	int index;
	int pindex;

	_arr.push_back(val);
	index = _arr.size() - 1;
	pindex = ParentOf_(index);

	while (_arr[pindex] < _arr[index])
	{
		std::swap(_arr[pindex], _arr[index]);
		index = pindex;
		pindex = ParentOf_(index);
	}
}


void	Heap::ExtractTop()
{
	// let's swap top with last first
	std::swap(_arr[0], _arr[_arr.size() - 1]);
	_arr.pop_back();
	int size(_arr.size());
	int index = 0;
	int nx;
	do 
	{
		nx = MaxIndex_(index);
		if (_arr[index] < _arr[nx])
			std::swap(_arr[index], _arr[nx]);
		else
			break ;
	}while (nx < size);
}

TYPE	Heap::Peek() const
{
	return _arr[0];
}

int		Heap::ParentOf_(int index)
{
	return (index - 1)/2;
}

int		Heap::RightOf_(int index)
{
	return (2 * index) + 2;
}

int		Heap::LeftOf_(int index)
{
	return (2 * index) + 1;
}

int		Heap::MaxIndex_(int index)
{
	if (_arr[LeftOf_(index)] < _arr[RightOf_(index)])
		return RightOf_(index);
	return LeftOf_(index);
}
