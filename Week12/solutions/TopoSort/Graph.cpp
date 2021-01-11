#include "Graph.h"

Graph::Graph(std::ifstream& in)
{
	in >> vertices >> edges;
	adj.resize(vertices + 1);

	int u, v;
	
	for(int i = 0; i < edges; i++)
	{
		in >> u >> v;
		addEdge(u, v);
	}
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

std::vector<int> Graph::adjacent(int v) const
{
	return adj[v];
}

int Graph::V() const
{
	return vertices;
}
