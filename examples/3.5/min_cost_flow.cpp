/**
  * @file Bellman-Ford for min cost flow 
  * @author malin
  * @date
  * @brief
  * @version
  */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <memory.h>

using namespace std;

typedef pair<int, int> P;

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<P> VP;
typedef vector<bool> VB;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();
const int MAXREAL = numeric_limits<double>::max();
const int MINREAL = numeric_limits<double>::min();

#define FOR1(i, s, t) for (i = s; i != t; ++i)
#define FOR2(i, s, t) for (i = s; i >= t; --i)


const int INF = std::numeric_limits<int>::max()/2;
const int MAX_V = 1000;

struct edge
{
	int to, cap, cost, rev;
};


vector<edge> G[MAX_V];
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
		fill(dist, dist + V, INF); dist[s] = 0;
		
		bool update = true;
		
		// Bellman-Ford
		while (update)
		{
			update = false;
			
			for (int v = 0; v != V; ++v)
			{
				for (int i = 0; i != G[v].size(); ++i)
				{
					auto& e = G[v][i];
					
					if (dist[e.to] > dist[v] + e.cost)
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


int main(int argc, char** argv)
{
	return 0;
}

/*

for convenient

*/

