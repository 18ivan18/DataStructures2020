#include "Graph.h"

Graph::Graph(std::ifstream& in)
{
	in >> vertices >> edges;
	adj.resize(vertices + 1);

	int u, v, w;
	
	for(int i = 0; i < edges; i++)
	{
		in >> u >> v >> w;
		addEdge(u, v, w);
	}
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back({ v, w });
}

std::vector<std::pair<int, int>> Graph::adjacent(int v) const
{
	return adj[v];
}

int Graph::V() const
{
	return vertices;
}
