#include <iostream>
#include <vector>


// a simple implment of min heap

// here i'm not checking errors at all i want just concept of the structure
typedef	int	type;


template <typename T>
class	heap_ds
{
	public:
		heap_ds() : _arr() {}

		void	insert(const T &value)
		{
			local_insert(value);
		}
		
		T	delete_min()
		{
			T v(_arr[0]);
			local_delete();
			return v;
		}
		void	_display() const
		{
			for (T v : _arr)
				std::cout << v << " ";
			std::cout << std::endl;
		}
		T	peek() const
		{
			return _arr[0];
		}
		int	size() const
		{
			return _arr.size();
		}
		
	private:
		int	left_of(int i)
		{
			return (2 * i) + 1;
		}
		int	right_of(int i)
		{
			return (2 * i) + 2;
		}

		int	parent_of(int i)
		{
			return (i - 1)/2;
		}
		
		void	local_insert(const T &value)
		{
			_arr.push_back(value);
			ci = _arr.size() - 1;
			pi = parent_of(ci);

			while (_arr[pi] > _arr[ci])
			{
				std::swap(_arr[pi], _arr[ci]);
				ci = pi;
				pi = parent_of(ci);
			}
		}
		void	local_delete()
		{
			int size(_arr.size());
			int swi; // help to swap index
			ci = 0;
			std::swap(_arr[0], _arr[size - 1]);
			_arr.pop_back();
			--size;
			if (size <= 0)
				return ;
			while (1)
			{
				li = left_of(ci);
				if (li < size)
				{
					swi = li;
					ri = right_of(ci);
					if (ri < size)
						if (_arr[li] > _arr[ri])
							swi = ri;
					if (_arr[ci] > _arr[swi])
					{
						std::swap(_arr[ci], _arr[swi]);
						ci = swi;
					}else
						break ;
				}
				else
					break ;
			}
		}
		int	pi; // stands for parent index
		int	ci; // current index (last elemen index)
		int	li;
		int	ri;
		std::vector<T>	_arr;
};


int main()
{
	int size;
	heap_ds<type>	heap;
	srand(time(NULL));
	std::cout << "size: ";
	std::cin >> size;

	std::vector<type> v(size);
	for (int i = 0; i < size; ++i)
	{
		v[i] = rand() % 100;
		heap.insert(v[i]);
		std::cout << v[i] << ", ";
	}

	std::cout << std::endl;

	for (int i = 0; i < size; ++i)
		std::cout << heap.delete_min() << " ";
	std::cout << std::endl;
}
