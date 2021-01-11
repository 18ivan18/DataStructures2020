#pragma once
#include <vector>
#include "Graph.h"

class TopoSort
{
private:
	std::vector<bool> visited;
	std::vector<int> answer;

	void dfs(const Graph& graph, int start);
public:
	TopoSort(const Graph& graph);

	void printAnswer() const;
};

