/** @file
  * @brief Path Restore
  * @author malin
  * @date
  * @version 1.0
  * @note
  * Using Dijkstra as an example.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();

const double MAXREAL = numeric_limits<double>::max();
const double MINREAL = numeric_limits<double>::min();

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<pair<int, int> > VP;

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class PR
{
	class edge
	{
	public:
		edge(int a, int b) : t(a), cost(b) {}
		
		int t, cost;
	};
	
public:
	VI minDistance(vector<VI> g, int V, int s)
	{
		vector<vector<edge> > G(V);
		
		for (auto& v : g)
		{
			G[v[0]].push_back(edge(v[1], v[2]));
		}
		
		VI d(V, MAXINT/2); d[s] = 0;
		prev.resize(V, -1);
		
		priority_queue<P, VP, greater<P> > que;
		
		que.push(P(0, s));
		
		while (!que.empty())
		{
			P p = que.top(); que.pop();
			
			if (d[p.second] >= p.first)
			{
				for (auto& e : G[p.second])
				{
					if (d[e.t] > d[p.second] + e.cost)
					{
						d[e.t] = d[p.second] + e.cost;
						prev[e.t] = p.second;
						que.push(P(d[e.t], e.t));
					}
				}
			}
		}
		
		return move(d);
	}
	
	VI getPath(int t)
	{
		VI path;
		for (; t != -1; t = prev[t]) path.push_back(t);
		reverse(path.begin(), path.end());
		
		return move(path);
	}
	
private:
	VI prev;
	
};

int main(int argc, char* argv[])
{
	return 0;
}

/**
  * just for convenient
  */

