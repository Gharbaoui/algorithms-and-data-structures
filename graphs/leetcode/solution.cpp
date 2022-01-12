
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
    static const int max=100;
    bool visited[max], added[max];
    
    Node* cloneGraph(Node* node) {
        int cur;
        Node    *cp = new Node[max];
        std::list<int>  st;
        
        init();
        cur = node[0].val;
        st.push_back(cur);
        visited[cur - 1] = true;
        
        while (!st.empty())
        {
            cur = st.front() - 1; // plays here as index
            st.pop_front();
            if (!added[cur])
            {
                cp[cur] = GetEntireNodeObjAtAndAddToSt(node[cur], st);
                added[cur] = true;
            }
        }
        return cp;
    }

    Node    GetEntireNodeObjAtAndAddToSt(const Node &cur, std::list<int> &st)
    {
        Node tmp;
        int at;
        std::vector<Node*>::const_iterator first, last;
        
        first = cur.neighbors.begin();
        last = cur.neighbors.end();
        tmp.val = cur.val;
        while (first != last)
        {
            tmp.neighbors.push_back(new Node(((*first)->val)));
            at = (*first)->val - 1;
            if (!visited[at])
            {
                st.push_back(at + 1);
                visited[at] = true;               
            }
            ++first;
        }
        return tmp;
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
