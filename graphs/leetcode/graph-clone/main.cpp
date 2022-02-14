#include <iostream>
#include <vector>
#include <list>
#include "solution1.cpp"

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

void	free_all(Node *cur, int size)
{
	Node *tmp;
	for (int i = 0; i < size; ++i)
	{
		tmp = cur + i;
		for (Node *var : tmp->neighbors)
			delete var;
	}
	delete [] cur;
}

int main()
{
	std::vector<Node*> tmp(4);

	tmp[0] = new Node(1);
	tmp[1] = new Node(2);
	tmp[2] = new Node(3);
	tmp[3] = new Node(4);

	tmp[0]->neighbors.push_back(tmp[1]);
	tmp[0]->neighbors.push_back(tmp[3]);

	tmp[1]->neighbors.push_back(tmp[0]);
	tmp[1]->neighbors.push_back(tmp[2]);

	tmp[2]->neighbors.push_back(tmp[1]);
	tmp[2]->neighbors.push_back(tmp[3]);

	tmp[3]->neighbors.push_back(tmp[0]);
	tmp[3]->neighbors.push_back(tmp[2]);

	Solution s;
	Node *other = s.cloneGraph(tmp[0]);
}
