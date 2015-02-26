#ifndef MAX_FLOW_F_H
#define MAX_FLOW_F_H


/**
  * @file Ford-Fulkerson for max_flow
  * @author malin
  * @date
  * @brief
  * @version
  */


#include <vector>
#include <limits>
#include <math.h>
#include <memory.h>


const int INF = std::numeric_limits<int>::max()/2;
const int MAX_V = 1000;

struct edge
{
	int to, cap, rev;
};

std::vector<edge> G[MAX_V];
bool used[MAX_V];


void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to, cap, (int)G[to].size()});
	G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

int dfs(int v, int t, int f)
{
	if (v == t)
	{
		return f;
	}
	
	used[v] = true;
	
	for (auto& e : G[v])
	{
		if (!used[e.to] && e.cap > 0)
		{
			int d = dfs(e.to, t, std::min(f, e.cap));
			
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				
				return d;
			}
		}
	}
	
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	
	for (;;)
	{
		memset(used, 0, sizeof(used));
		
		int f = dfs(s, t, INF);
		
		if (f == 0) return flow;
		
		flow += f;
	}
}


#endif	// MAX_FLOW_F_H
