#include <memory>
#include <exception>
#include <list>
#include <utility>

/*
  a simple implementation of hash table using std list
  with some move constructors and assigment
 */


template <typename T, typename __alloc=std::allocator<T>>
struct	HashTable
{
	public:
		explicit HashTable(size_t size, const std::function<size_t (T)> &);
		HashTable(const HashTable &) = delete;
		~HashTable();
		HashTable&operator=(const HashTable &rhs) = delete;
		HashTable(HashTable &&) noexcept; // move constructor
		HashTable&operator=(HashTable &&) noexcept; // move assigment operator
		void	insert(const T &);
		template <typename InputIter>
		void	insert(InputIter first, InputIter last);
		std::pair<bool, T&>	find(const T &);	
	private:
		size_t					arr_size;
		T						invalidVal;
		typename __alloc::template rebind<std::list<T, __alloc>>::other	alloc;
		std::list<T, __alloc> *_arr;
		std::function<size_t (T)> hash;
};

template <typename T, typename __alloc>
HashTable<T, __alloc>::~HashTable()
{
	for (size_t i = 0; i < arr_size; ++i)
		alloc.destroy(_arr + i);
	alloc.deallocate(_arr, arr_size);
}

template <typename T, typename __alloc>
HashTable<T, __alloc>::HashTable(HashTable &&cp) noexcept
{
	*this = std::move(cp);
}

template <typename T, typename __alloc>
HashTable<T, __alloc>& HashTable<T, __alloc>::operator= (HashTable &&rhs) noexcept
{
	_arr = rhs._arr;
	hash = rhs.hash;
	alloc = rhs.alloc;
	arr_size = rhs.arr_size;
	rhs.arr_size = 0;
	rhs._arr = nullptr;
	return *this;
}

template <typename T, typename __alloc>
HashTable<T, __alloc>::HashTable(size_t size, const std::function<size_t (T)> &hashfunc)
{
	arr_size = size;
	hash = hashfunc;

	_arr = alloc.allocate(arr_size);
	for (size_t i = 0; i < arr_size; ++i)
		alloc.construct(_arr + i);
}

template <typename T, typename __alloc>
void	HashTable<T, __alloc>::insert(const T &item)
{
	size_t index = hash(item);
	if (index >= arr_size)
		throw "hash functions give index that is bigger than our array";
	_arr[index].push_front(item);
}

template <typename T, typename __alloc>
template <typename InputIter>
void	HashTable<T, __alloc>::insert(InputIter first, InputIter last)
{
	while (first != last)
	{
		insert(*first);
		++first;
	}
}

template <typename T, typename __alloc>
std::pair<bool, T&>	HashTable<T, __alloc>::find(const T &target)
{
	size_t index = hash(target);
	if (index >= arr_size)
		throw "hash functions give index that is bigger than our array";
	std::list<T, __alloc> &list = _arr[index];
	for (auto &val : list)
		if (val == target)
			return std::pair<bool, T&>(true, val);
	return std::pair<bool, T&>(false, invalidVal);
}
