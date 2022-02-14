
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
    static const int MAX = 100;
    std::vector<Node*> holder;
    bool    done[MAX];
    bool    allocated[MAX];

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        else if (node[0].neighbors.size() == 0)
            return new Node(node->val);
        init();
        holder.assign(MAX, nullptr);
        StartCopy(node);
        return holder[0];
    }
    
    void    StartCopy(Node *node)
    {
        int Index;
        int valI;
        std::vector<Node*>::const_iterator first, last;
        first = node->neighbors.begin();
        last = node->neighbors.end();
        Index = node->val - 1;
        if (!allocated[Index])
	{
         	allocated[Index] = true;
		holder[Index] = new Node(Index + 1);
        }
        while (first != last)
        {
            valI = (*first)->val - 1;
            if (!allocated[valI]){
		allocated[valI] = true;
                holder[valI] = new Node(valI + 1);
		}
            holder[Index]->neighbors.push_back(holder[valI]);
            ++first;
        }
        done[Index] = true;
        first = node->neighbors.begin();
        last = node->neighbors.end();
        while (first != last)
        {
            if (!done[(*first)->val - 1])
                StartCopy(*first);
            ++first;
        }   
    }
    void    init()
    {
        for (int i = 0; i < MAX; ++i) {
            allocated[i] = false;
            done[i] = false;
        }
    }

    
};
