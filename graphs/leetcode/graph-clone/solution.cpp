
// Definition for a Node.

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
	std::vector<Node*>::const_iterator	first, last;
	static const int max=100;
	bool visited[max], added[max];
	Node *cp;
	Node *target;

	Node* cloneGraph(Node* node) {
		if (node == NULL)
			return NULL;
		if (node[0].neighbors.size() == 0)
			return new Node(node[0].val);
		cp = new Node[100];
		init();
		target = node;
		StartCopy(0);
		return cp;
	}

	void	StartCopy(int curIndex)
	{
		std::vector<Node*>::const_iterator	first, last;
		if (!visited[curIndex])
		{
			visited[curIndex] = true;
			FillEntireNodeObj(target[curIndex], cp[curIndex]);
		}
		first = target[curIndex].neighbors.begin();
		last = target[curIndex].neighbors.end();

		while (first != last)
		{
			if (!visited[(*first)->val - 1])
				StartCopy((*first)->val - 1);
			++first;
		}
	}

	void	FillEntireNodeObj(const Node &cur, Node &here)
	{
		first = cur.neighbors.begin();
		last = cur.neighbors.end();
		here.val = cur.val;
		here.neighbors.clear();
		while (first != last)
		{
			here.neighbors.push_back(new Node((*first)->val));
			++first;
		}
	}

	void    init()
	{
		for (int i = 0; i < max; ++i)
		{
			visited[i] = false;
			added[i] = false;
		}
	}

};
