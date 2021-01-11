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

	int nt;

	in >> nt;

	for(int i = 0; i < nt; i++)
	{
		Graph graph = Graph(in);
		Dijkstra dijkstra(graph, 1);

		std::cout << dijkstra.getDistanceTo(graph.V()) << '\n';
	}
}