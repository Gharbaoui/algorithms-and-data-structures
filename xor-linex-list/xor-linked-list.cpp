#include <iostream>
#include "xor-linked-list.hpp"
#include <vector>

struct Gen
{
	Gen() {srand(time(nullptr));}
	int	operator()(){return rand() % 100 - rand() % 100;}
};

int main()
{
	XorLinkedListCont<int> ls;

	std::vector<int>  arr(20);

	std::generate(arr.begin(), arr.end(), Gen());
	for (auto v : arr)
		std::cout << v << " ";
	std::cout << "\n";
	ls.insert(arr.begin(), arr.end());

	XorLinkedListCont<int>::iterator iterL(ls.end());
	XorLinkedListCont<int>::iterator iterF(ls.begin());

	for (;iterF != iterL;)
	{
		std::cout << *iterF << " ";
		++iterF;
	}
	std::cout << "\n";

}
