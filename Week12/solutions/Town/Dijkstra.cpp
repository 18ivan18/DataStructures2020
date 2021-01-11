#include "Dijkstra.h"

#include <iostream>
#include <set>
#include <stack>

void Dijkstra::dijkstra(const Graph& graph, int s)
{
	distance[s] = 0;
	std::set<std::pair<int, int>> q;
	q.insert({ 0, s });

	while(!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());

		for(const std::pair<int, int> edge : graph.adjacent(v))
		{
			int toVertice = edge.first;
			int length = edge.second;

			if(distance[v] + length < distance[toVertice])
			{
				q.erase({ distance[toVertice], toVertice });
				distance[toVertice] = distance[v] + length;
				parent[toVertice] = v;
				q.insert({ distance[toVertice], toVertice });
			}
		}
	}
}

Dijkstra::Dijkstra(const Graph& graph, int _start) : start(_start)
{
	int graphSize = graph.V() + 1;
	INF = 1000000000;
	
	distance.assign(graphSize, INF);
	parent.assign(graphSize, -1);

	dijkstra(graph, _start);
}

bool Dijkstra::hasPathTo(int v) const
{
	return distance[v] != INF;
}

int Dijkstra::getDistanceTo(int v) const
{
	return distance[v];
}

void Dijkstra::printPathTo(int v) const
{
	if(!hasPathTo(v))
	{
		std::cout << "No path!\n";
	}
	
	std::stack<int> path;

	while(parent[v] != -1)
	{
		path.push(v);
		v = parent[v];
	}
	path.push(start);

	while(!path.empty())
	{
		std::cout << path.top();
		path.pop();
		if(!path.empty())
		{
			std::cout << " - ";
		}
	}

	std::cout << '\n';
}
