/** @file
  * @brief Prim
  * @author malin
  * @date
  * @version 1.0
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


class edge
{
public:
	edge(int a, int b) : t(a), c(b) {}
	
	int t, c;
	
};

class Prim
{
public:
	int minCost(vector<VI> g, int V)
	{
		vector<vector<edge> > G(g.size());
		
		for (auto& v : g)
		{
			G[v[0]].push_back(edge(v[1], v[2]));
		}
		
		VI d(V, MAXINT/2); d[0] = 0;
		
		priority_queue<P, VP, greater<P> > que;
		que.push(P(0, 0));
		
		int ans = 0;
		
		while (!que.empty())
		{
			P p = que.top(); que.top();
			
			int v = p.second;
			
			if (d[v] >= p.first)
			{
				ans += p.first;
				
				for (auto& x : G[v])
				{
					if (d[x.t] > x.c)
					{
						d[x.t] = x.c;
						que.push(P(x.c, x.t));
					}
				}
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	return 0;
}

/**
  * just for convenient
  */

