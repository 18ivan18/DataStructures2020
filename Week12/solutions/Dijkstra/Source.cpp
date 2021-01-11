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

	Graph* graph = new Graph(in);
	Dijkstra dijkstra(*graph, 1);

	std::cout << "Has path to 5? " << std::boolalpha << dijkstra.hasPathTo(5) << "  Length:" << dijkstra.getDistanceTo(5) << "\n"
		      << "Has path to 2? " << std::boolalpha << dijkstra.hasPathTo(2) << "  Length:" << dijkstra.getDistanceTo(2) << "\n";
	std::cout << "Path to 5: \n";
	dijkstra.printPathTo(5);

	std::cout << "Path to 2: \n";
	dijkstra.printPathTo(2);
	
	delete graph;
}