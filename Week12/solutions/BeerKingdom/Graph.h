#pragma once
#include <fstream>
#include <vector>

class Graph
{
private:
	std::vector<std::vector<std::pair<int, int>>> adj;
	int vertices;
	int edges;

public:
	Graph(std::ifstream&);

	void addEdge(int u, int v, int w);
	std::vector<std::pair<int, int>> adjacent(int v) const;

	int V() const;
};

