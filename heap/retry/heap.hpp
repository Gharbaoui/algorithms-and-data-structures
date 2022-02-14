#ifndef __HEAP__
#define __HEAP__

#include <iostream>
#include <vector>
// using less operator so the biggest will be at the top it's easy to change that later
using TYPE=int;

class Heap
{
	private:
		std::vector<TYPE> _arr;
		inline int		ParentOf_(int index);
		inline int		LeftOf_(int index);
		inline int		RightOf_(int index);
		inline int		MaxIndex_(int index);
	public:
		Heap (int);
		Heap() = default;
		void	Insert(const TYPE &);
		TYPE	Peek() const;
		void	ExtractTop();
};

#endif
