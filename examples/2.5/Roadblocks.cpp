/** @file
  * @brief Roadblocks
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

class RB
{
public:
	int sminDistance(vector<VI> g, int V)
	{
		vector<vector<edge> > G(g.size());

		for (auto& v : g)
		{
			G[v[0]].push_back(edge(v[1], v[2]));
		}

		VI d1(V, MAXINT/2), d2(V, MAXINT/2); d1[0] = 0;
		
		priority_queue<P, VP, greater<P> > que; que.push(P(0, 0));

		while (!que.empty())
		{
			P p = que.top(); que.pop();

			int v = p.second, d = p.first;

			if (d2[v] < d) continue;

			for (auto& e : G[v])
			{
				int dd = d + e.c;
				
				if (d1[e.t] > dd)
				{
					swap(d1[e.t], dd);
					que.push(P(d1[e.t], e.t));
				}
				
				if (d2[e.t] > dd && d1[e.t] < dd)
				{
					d2[e.t] = dd;
					que.push(P(dd, e.t));
				}
			}
		}
		
		return d2[V-1];
	}
	
};

int main(int argc, char* argv[])
{
	RB a;
	
	cout << a.sminDistance({{0, 1, 100}, {1, 2, 250}, {2, 3, 100}, {1, 3, 200}}, 4) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

