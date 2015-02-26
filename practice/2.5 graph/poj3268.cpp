/** @file
  * @brief POJ3268 Silver Cow party
  * @author malin
  * @date 2014年07月13日 星期日 09时52分10秒
  * @version 1.0
  * The main idea is to find the shortest path from X to the other vertices, and the shortest path from the other vertices, so
  * we can use the dijkstra method to solve this problem.
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

class SCP
{
public:
	int longestTime(int N, vector<VI> M, int X)
	{
		vector<vector<edge> > G1(N), G2(N);

		for (auto& v : M)
		{
			G1[v[1] - 1].push_back(edge(v[0] - 1, v[2]));
			G2[v[0] - 1].push_back(edge(v[1] - 1, v[2]));
		}

		VI d1(N, MAXINT/2), d2(N, MAXINT/2);
		d1[X - 1] = 0; d2[X - 1] = 0;

		dijkstra(d1, G1, X);
		dijkstra(d2, G2, X);

		int i, ans = 0;

		FOR1(i, 0, N)
		{
			ans = max(ans, d1[i] + d2[i]);
		}

		return ans;
	}

private:
	void dijkstra(VI& d, vector<vector<edge> >& G, int X)
	{
		priority_queue<P, VP, greater<P> > q;
		q.push(P(0, X - 1));

		while (!q.empty())
		{
			P p = q.top(); q.pop();

			int v = p.second;

			if (d[v] >= p.first)
			{
				for (auto& e : G[v])
				{
					if (d[e.t] > d[v] + e.c)
					{
						d[e.t] = d[v] + e.c;
						q.push(P(d[e.t], e.t));
					}
				}
			}
		}
	}


};

int main(int argc, char** argv)
{
	SCP a;
	
	cout << a.longestTime(4, {{1, 2, 4}, {1, 3, 2}, {1, 4, 7}, {2, 1, 1}, {2, 3, 5}, {3, 1, 2}, {3, 4, 4}, {4, 2, 3}}, 2) << endl;
	
	return 0;
}
