#pragma once
#include <fstream>
#include <vector>
#define REV_W 400002
class Graph
{
private:
	std::vector<std::vector<std::pair<int, int>>> adj;
	int vertices;
	int edges;
public:
	Graph(std::ifstream&, int _vertices);

	void addEdge(int u, int v, int w);
	std::vector<std::pair<int, int>> adjacent(int v) const;

	int V() const;
};