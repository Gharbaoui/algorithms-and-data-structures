#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <utility>
#include <memory>
#include <iostream>
#include <list>
#include <functional>

#define MX_VERTEX 100
#define NULL_PTR 0

// class template for vertex
template <typename T>
class	VertexInGraph
{
	public:
		// constructors
		VertexInGraph() : apNext(NULL_PTR) {}
		VertexInGraph(const T &id) : apNext(NULL_PTR), aVertexId(id) {}
		VertexInGraph &operator=(const VertexInGraph &rhs)
		{
			apNext = rhs.apNext;
			aVertexId = rhs.aVertexId;
			return *this;
		}
		// access
		VertexInGraph	*GetNextVertex() const {return apNext;}
		T		GetVertexId() const {return aVertexId;}
		void		SetNextVertex(VertexInGraph *nextVer) {apNext = nextVer;}
	
	private:
		VertexInGraph	*apNext;
		T		aVertexId;
};

// class for undirected graph data structure implmentation is adjacency list
class Graph
{
	public:
		// constructors
		// default constructor
		Graph();
		// take first paramter as number of vertics second number of edges
		Graph(unsigned int, unsigned int);
		// operations functions
		
		// since in this situation i'm using int's as id of vertex 
		// take edge
		void	Insert(const std::pair<int, int> &edge);
		template <typename Iter>
		void	Insert(Iter first, Iter last);

		// algorithms of the graph
		// depth first traversal starts from start variable
		void	DepthFirstTraversal(int start, const std::function <void (int)> &excute);
		void	DFSAddNeighToBeProccessed(int index, std::list<int> &unProccessedVertices);
		// breath first search
		void	BreathFirstTraversal(int start, const std::function <void (int)> &excute);
		void	BFSAddNeighToBeProccessed(int index, std::list<int> &unProccessedVertices);

		// shortest path using breath first search
		void	BFShortestPath(int start, int end);
		void	ReconstructRoute(std::list<std::pair<int, int>> &rout, int start, int end);
		// display graph
		void	display();
	private:
		// takes to array of bool and fill wiht value from 0 to n
		void	FillArrBool(bool *arr, bool value, int n);
		// intilize aProccessed and aVisited to false
		void	InitArrsBool(int n);
		// will initilize array of pointer vertices with null at construction
		void	InitVertices(int n);
		// insert one edge
		void	PrInsert(const std::pair<int, int> &edge);
	private:
		typedef	VertexInGraph<int>	Vertex;
	private:
		Vertex			*apVertices[MX_VERTEX];
		unsigned int		aNumvertices;
		unsigned int		aNumEdges;
		bool			aProccessed[MX_VERTEX + 1];
		bool			aVisited[MX_VERTEX + 1];
		std::allocator<Vertex>	aVertexAlloc;
};


template <typename Iter>
void	Graph::Insert(Iter first, Iter last)
{
	while (first != last)
	{
		Insert(*first);
		++first;
	}
}
#endif
