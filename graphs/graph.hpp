#ifndef __GRAPH__
#define __GRAPH__

#define MX_EDGES 100

#include <iostream>


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
	
	public:
		Graph()
		{
			for (int i = 0; i < MX_EDGES + 1; ++i)
			{
				edges[i] = NULL;
				connect_edges[i] = 0;
			}
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




		void	display() const
		{
			for (int i = 0; i < MX_EDGES + 1; ++i)
				if (edges[i])
					display_row(i, edges[i]);
		}

		void	display_row(int index, Edge *start_node) const
		{
			std::cout << "| " << index << " | ";
			while (start_node)
			{
				std::cout << "( " << start_node->getId() << " ) ";
				if (start_node->getNext())
					std::cout << "-> ";
				start_node = start_node->getNext();
			}
			std::cout << "[" << connect_edges[index] << "]" << std::endl; 
		}
};



#endif
