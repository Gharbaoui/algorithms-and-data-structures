#ifndef __GRAPH__
#define __GRAPH__

#define MX_EDGES 100

#include <iostream>
#include <stack>

//	[0]-----[1]----[2]
//	| ______| |	|
//	||	  |	|
//	[4]-----[3]-----|



// implment undirect graph as adjacency list not adjacency matrix

// this is struct for an edge in graph
class	Edge{
	int _id; // this variable will b e unique to each edge in graph
	Edge *_next;

	public:
		Edge(int id) : _id(id) {}
		void	setNext(Edge *next_edge) 
		{
			_next = next_edge;
		}
		Edge	*getNext() const
		{
			return _next;
		}
		int	getId() const
		{
			return _id;
		}
};

// in simple words graph in this (adjacency list) is jutst array of linked lists
// it will be clear whene you see the code
class Graph
{
	Edge	*edges[MX_EDGES + 1]; // +1 in my case i will insert edges usually start from 1
	int	connect_edges[MX_EDGES + 1]; // this will tell me how many edges are connect to each one of my edges
	int	nverteces;
	bool	visited[MX_EDGES + 1];
	
	public:
		Graph()
		{
			for (int i = 0; i < MX_EDGES + 1; ++i)
			{
				edges[i] = NULL;
				connect_edges[i] = 0;
			}
			nverteces = 0;
		}

		// function will accept two ids of edge
		void	insert(int id1, int id2)
		{
			// remember we are implmenting undirect graph
			// a -- b is same as b -- a
			insert_one_pair(id1, id2);
			insert_one_pair(id2, id1);
		}

		void	insert_one_pair(int id1, int id2)
		{
			Edge *edge2 = new Edge(id2);
			edge2->setNext(edges[id1]);
			edges[id1] = edge2;
			++connect_edges[id1];
		}

		void	setNumberOfVerteces(int n)
		{
			nverteces = n;
		}

		void	dfs_trvaresal(int start)
		{
			for (int i = 0; i < MX_EDGES + 1; ++i)
				visited[i] = false;
			std::cout << "recursion\n";
			pr_dfs_rec(start);
			std::cout << std::endl;

			std::cout << "iteration\n";
			for (int i = 0; i < MX_EDGES + 1; ++i)
				visited[i] = false;
			pr_dfs_iter(start);
			std::cout << std::endl;
		}
	private:
		void	pr_dfs_rec(int start)
		{
			Edge *tmp = edges[start];
			if (!visited[start])
			{
				std::cout << start << " ";
				visited[start] = true;
			}
			
			while (tmp)
			{
				if (!visited[tmp->getId()])
					pr_dfs_rec(tmp->getId());
				tmp = tmp->getNext();
			}
		}
		void	pr_dfs_iter(int start)
		{
			std::stack<int> edges_to_visit;
			Edge *tmp;
			int cur;
			edges_to_visit.push(start);
			while (!edges_to_visit.empty())
			{
				cur  = edges_to_visit.top();
				edges_to_visit.pop();
				if (!visited[cur])
				{
					std::cout << cur << " ";
					visited[cur] = true;
				}
				tmp = edges[cur];
				while (tmp)
				{
					if (!visited[tmp->getId()])
						edges_to_visit.push(tmp->getId());
					tmp = tmp->getNext();
				}
			}
		}


};



#endif