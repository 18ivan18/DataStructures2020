#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Dijkstra.h"

int main()
{
	std::string inFilename = "graph.txt";
	std::ifstream in(inFilename);

	if(!in)
	{
		std::cerr << "Invalid filename\n";
	}

	int n, a, b;

	in >> n >> a >> b;

	Graph* graph = new Graph(in, n);
	Dijkstra dijkstra(*graph, a);

	if(!dijkstra.hasPathTo(b))
	{
		std::cout << "X\n";
	}
	else
	{
		std::cout << dijkstra.getDistanceTo(b) % REV_W << '\n';
	}
	
	delete graph;
}