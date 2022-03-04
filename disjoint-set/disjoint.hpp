#ifndef __DISJOINT__
#define __DISJOINT__
#include <vector>
#include <utility>
#include <unordered_map>
template <typename T>
struct	OneSet
{
	public:
		size_t	size() {return elms.size();}
		void	insert(const T &item, bool is_rp = false)
		{
			elms.push_back(item);
			if (is_rp)
				_repr = item;
		}

		T&		operator[](size_t index){
			return elms[index];
		}

		std::vector<T>&	getVect()
		{
			return elms;
		}

		T&		getRepresentive()
		{
			return _repr;
		}
	private:
		T				_repr;
		std::vector<T>	elms;
};

// naive implmentation just for getting sens for what is this data struture
template <typename T>
struct	DisjointSet
{
	public:
		explicit DisjointSet(std::vector<OneSet<T>> &sts, const T &nis);
		DisjointSet() = delete;
		DisjointSet(const DisjointSet &) = delete;
		DisjointSet&operator=(const DisjointSet&) = delete;
		friend	std::ostream& operator<<(std::ostream &os, DisjointSet &ds)
		{
			for (auto &v: ds._dst)
				os << "{" << v.first << ", " << v.second << "} ";
			return os;
		}
		T	find(const T &);
		void	unite(T, T);
	private:
		T							notInSet;
		std::vector<std::pair<T, T>> _dst;
};

template<typename T>
DisjointSet<T>::DisjointSet(std::vector<OneSet<T>> &sts, const T &nis)
{
	notInSet = nis;
	T rep;
	for (auto &v : sts)
	{
		rep = v.getRepresentive();
		for (auto &val: v.getVect())
			_dst.push_back(std::make_pair(rep, val));
	}
}

template<typename T>
T	DisjointSet<T>::find(const T &target)
{
	for (auto &v : _dst) // will loop n times where n is the number of all elemnts in all sets combined (for example set1 has 2 and set2 has 5 ) n will be 2 + 5 = 7 ==> n = 7
	{
		if (v.second == target)
			return v.first;
	}
	return notInSet;
}

template <typename T>
void	DisjointSet<T>::unite(T x, T y)
{
	//i'm assuming that x and y are valid elemnts
	x = this->find(x);
	y = this->find(y);

	for (auto &v: _dst) // also dependet on all the elments
		if (v.first == x)
			v.first = y;
}


#endif
