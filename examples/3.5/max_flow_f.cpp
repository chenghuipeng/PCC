/**
  * @file Ford-Fulkerson for max_flow
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

const int INF = numeric_limits<int>::max()/2;
const int MAX_V = 1000;

struct edge
{
	int to, cap, rev;
};

vector<edge> G[MAX_V];
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
			int d = dfs(e.to, t, min(f, e.cap));
			
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


int main(int argc, char** argv)
{
	return 0;
}

/*

for convenient

*/

