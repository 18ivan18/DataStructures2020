#include "TopoSort.h"

#include <iostream>

void TopoSort::dfs(const Graph& graph, int start)
{
	visited[start] = true;
	for(const int& u : graph.adjacent(start))
	{
		if(!visited[u])
		{
			dfs(graph, u);
		}
	}

	answer.push_back(start);
}

TopoSort::TopoSort(const Graph& graph)
{
	int graphSize = graph.V();
	
	visited.assign(graphSize, false);

	for(int i = 0; i < graphSize; i++)
	{
		if(!visited[i])
		{
			dfs(graph, i);
		}
	}

	std::reverse(answer.begin(), answer.end());
}

void TopoSort::printAnswer() const
{
	for(const int& v : answer)
	{
		std::cout << v << ' ';
	}

	std::cout << '\n';
}
