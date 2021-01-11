#pragma once
#include "Graph.h"

class Dijkstra
{
private:
	std::vector<int> distance;
	std::vector<int> parent;
	int start;
	int INF;

	void dijkstra(const Graph& graph, int s);
public:
	Dijkstra(const Graph& graph, int _start);
	bool hasPathTo(int v) const;
	int getDistanceTo(int v) const;
	void printPathTo(int v) const;
};

