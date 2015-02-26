#ifndef BIPARTITE_GRAPH_MATCH_H
#define BIPARTITE_GRAPH_MATCH_H


/**
  * @file bipartite graph match
  * @author malin
  * @date
  * @brief
  * @version
  */


#include <iostream>
#include <vector>
#include <memory.h>


const int MAX_V = 1000;

int V;
std::vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];


void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}


bool dfs(int v)
{
	used[v] = true;
	
	for (auto u : G[v])
	{
		int w = match[u];
		
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	
	return false;
}

int bipartite_matching()
{
	int ans = 0;
	
	memset(match, -1, sizeof(match));
	
	for (int i = 0; i != V; ++i)
	{
		memset(used, 0, sizeof(used));
		
		if (dfs(i))
		{
			++ ans;
			
//			std::cout << i << std::endl;
		}
	}
	
	return ans;
}


#endif	// BIPARTITE_GRAPH_MATCH_H
