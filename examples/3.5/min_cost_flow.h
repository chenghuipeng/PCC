#ifndef MIN_COST_FLOW_H
#define MIN_COST_FLOW_H


/**
  * @file Bellman-Ford for min cost flow 
  * @author malin
  * @date
  * @brief
  * @version
  */


#include <vector>
#include <algorithm>
#include <limits>
#include <memory.h>


const int INF = std::numeric_limits<int>::max()/2;
const int MAX_V = 1000;

struct edge
{
	int to, cap, cost, rev;
};


std::vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];


void add_edge(int from, int to, int cap, int cost)
{
	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}


int min_cost_flow(int s, int t, int f, int V)
{
	int ans = 0;
	
	while (f > 0)
	{
		std::fill(dist, dist + V, INF); dist[s] = 0;
		
		bool update = true;
		
		// Bellman-Ford
		while (update)
		{
			update = false;
			
			for (int v = 0; v != V; ++v)
			{
				if (dist[v] == INF) continue;
				
				for (int i = 0; i != G[v].size(); ++i)
				{
					auto& e = G[v][i];
					
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost)
					{
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i; 
						update = true;
					}
				}
			}
		}
		
		// can't find a flow which value is f
		if (dist[t] == INF)
		{
			return -1;
		}
		
		int d = f;
		
		for (int v = t; v != s; v = prevv[v])
		{
			d = std::min(d, G[prevv[v]][preve[v]].cap);
		}
		
		f -= d;
		ans += dist[t] * d;
		
		for (int v = t; v != s; v = prevv[v])
		{
			auto& e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[e.to][e.rev].cap += d;
		}
	}
	
	return ans;
}


#endif	// MIN_COST_FLOW_H
