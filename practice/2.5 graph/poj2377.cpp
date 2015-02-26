/** @file
  * @brief POJ2377 Bad Cowtractors
  * @author malin
  * @date 2014年07月13日 星期日 16时02分58秒
  * @version 1.0
  * In order to find wether the graph is connected, we use the dijkstra method.
  */

#include<iostream>
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


class BC
{
public:
	int maxCost(int N, vector<VI> M)
	{
		vector<vector<edge> > G(N);

		for (auto& v : M)
		{
			G[v[0] - 1].push_back(edge(v[1] - 1, v[2]));
			G[v[1] - 1].push_back(edge(v[0] - 1, v[2]));
		}

		VI d(N, -1); d[0] = 0;

		priority_queue<P> que; que.push(P(0, 0));

		int ans = 0;

		while (!que.empty())
		{
			P p = que.top(); que.pop();

			int v = p.second;

			if (d[v] <= p.first && d[v] != -2)
			{
				ans += p.first;

				d[v] = -2;

				for (auto& e : G[v])
				{
					if (d[e.t] < e.c && d[e.t] != -2)
					{
						d[e.t] = e.c;
						que.push(P(e.c, e.t));
					}
				}
			}
		}

		for (auto& x : d)
		{
			if (x == -1) return -1;
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	BC a;

	cout << a.maxCost(5, {{1, 2, 3}, {1, 3, 7}, {2, 3, 10}, {2, 4, 4}, {2, 5, 8}, {3, 4, 6}, {3, 5, 2}, {4, 5, 17}}) << endl;

	return 0;
}
