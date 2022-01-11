graph: ./objs/Graph.o ./objs/Depth-First-Search.o ./objs/Breath-first-search.o ./objs/shortest-path.o  ./objs/main.o ./objs/topological-sort.o
	clang++ ./objs/Graph.o ./objs/Depth-First-Search.o ./objs/Breath-first-search.o ./objs/shortest-path.o ./objs/topological-sort.o  ./objs/main.o  -o graph -std=c++11

./objs/Graph.o: Graph.cpp
	clang++ -c Graph.cpp -o ./objs/Graph.o

./objs/Depth-First-Search.o: Depth-First-Search.cpp
	clang++ -c Depth-First-Search.cpp -o ./objs/Depth-First-Search.o

./objs/Breath-first-search.o: Breath-first-search.cpp
	clang++ -c Breath-first-search.cpp -o ./objs/Breath-first-search.o

./objs/shortest-path.o: shortest-path.cpp
	clang++ -c shortest-path.cpp -o ./objs/shortest-path.o
./objs/main.o: main.cpp
	clang++ -c main.cpp -o ./objs/main.o
./objs/topological-sort.o: topological-sort.cpp
	clang++ -c topological-sort.cpp -o ./objs/topological-sort.o


clearobj:
	rm ./objs/*

clean:
	rm graph
