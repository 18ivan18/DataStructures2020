#include <iostream>
#include <fstream>
#include "Graph.h"
#include "TopoSort.h"

int main()
{
	std::string inFilename = "graph.txt";
	std::ifstream in(inFilename);

	if(!in)
	{
		std::cerr << "Invalid filename\n";
	}

	Graph* graph = new Graph(in);
	TopoSort topoSort(*graph);

	std::cout << "TopoSort:\n";
	topoSort.printAnswer();

	delete graph;
}