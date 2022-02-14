#include "heap.hpp"

int main()
{
	Heap h(10);


	std::vector<int> values{10, 30, 0, -5, 4, 100, 700};

	for (auto v: values)
		h.Insert(v);

	std::cout << h.Peek() << std::endl;

}
