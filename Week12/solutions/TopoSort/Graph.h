#pragma once
#include <fstream>
#include <vector>

class Graph
{
private:
	std::vector<std::vector<int>> adj;
	int vertices;
	int edges;

public:
	Graph(std::ifstream&);

	void addEdge(int u, int v);
	std::vector<int> adjacent(int v) const;

	int V() const;
};

