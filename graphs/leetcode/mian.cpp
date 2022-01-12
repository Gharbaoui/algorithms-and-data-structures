#include <iostream>
#include <vector>
#include <list>
#include "solution.cpp"

void	Display(Node *cur, int size)
{
	Node *tmp;
	for (int i = 0; i < size; ++i)
	{
		tmp = cur + i;
		std::cout << "AT: " << "{" << i << "} VAL: " << tmp->val << " -> ";
		for (auto item : tmp->neighbors)
			std::cout << item->val << " ,";
		std::cout << std::endl;
	}
}


int main()
{
	Node*	cur = new Node[4];

	cur[0].val = 1;
	cur[1].val = 2;
	cur[2].val = 3;
	cur[3].val = 4;

	cur[0].neighbors.push_back(new Node(2));
	cur[0].neighbors.push_back(new Node(4));
	
	cur[1].neighbors.push_back(new Node(1));
	cur[1].neighbors.push_back(new Node(3));
	
	cur[2].neighbors.push_back(new Node(2));
	cur[2].neighbors.push_back(new Node(4));
	
	cur[3].neighbors.push_back(new Node(1));
	cur[3].neighbors.push_back(new Node(3));


	Display(cur, 4);

	Solution s;
	Node *other = s.cloneGraph(cur);
	std::cout << std::endl;
	Display(cur, 4);
}
