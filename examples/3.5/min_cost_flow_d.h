#ifndef MIN_COST_FLOW_H
#define MIN_COST_FLOW_H


/**
  * @file Dijkstra for mnin cost flow 
  * @author malin
  * @date
  * @brief
  * @version
  */


#include <vector>
#include <algorithm>
#include <limits>
#include <memory.h>
#include <queue>


typedef std::pair<int, int> P;
const int INF = std::numeric_limits<int>::max()/2;
const int MAX_V = 1000;

struct edge
{
	int to, cap, cost, rev;
};


std::vector<edge> G[MAX_V];
int h[MAX_V];
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
	
	memset(h, 0, sizeof(h));
	
	while (f > 0)
	{
		std::fill(dist, dist + V, INF); dist[s] = 0;
		
		std::priority_queue<P, std::vector<P>, std::greater<P> > que; que.push(P(0, s));
		
		while (!que.empty())
		{
			P p = que.top(); que.pop();
			
			int v = p.second;
			
			if (dist[v] < p.first) continue;
			
			for (int i = 0; i != G[v].size(); ++i)
			{
				auto& e = G[v][i];
				
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
				{
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(P(dist[e.to], e.to));
				}
			}
		}
		
		if (dist[t] == INF)
		{
			return -1;
		}
		
		for (int i = 0; i != V; ++i)
		{
			h[i] += dist[i];
		}
		
		int d = f;
		
		for (int i = t; i != s; i = prevv[i])
		{
			d = std::min(d, G[prevv[i]][preve[i]].cap);
		}
		
		f -= d;
		
		ans += d * h[t];
		
		for (int i = t; i != s; i = prevv[i])
		{
			auto& e = G[prevv[i]][preve[i]];
			
			e.cap -= d;
			G[e.to][e.rev].cap += d;
		}
	}
	
	return ans;
}


#endif	// MIN_COST_FLOW_H
