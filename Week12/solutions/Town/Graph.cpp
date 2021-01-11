#include "Graph.h"

Graph::Graph(std::ifstream& in, int _vertices) : vertices(_vertices), edges(0)
{
	adj.resize(vertices + 1);

	int u, v;
	
	while(in)
	{
		in >> u >> v;
		addEdge(u, v, 1);
		edges++;
	}
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back({ v, w });
	adj[v].push_back({ u, REV_W });
}

std::vector<std::pair<int, int>> Graph::adjacent(int v) const
{
	return adj[v];
}

int Graph::V() const
{
	return vertices;
}
