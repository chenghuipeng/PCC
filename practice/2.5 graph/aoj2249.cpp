/** @file
  * @brief AOJ2249 Road Construction
  * @author malin
  * @date 2014年07月13日 星期日 10时49分09秒
  * @version 1.0
  * We can use the dijsktra method to find the shortest paths with the minimal total cost from captial to the other cities, and
  * remove the roads are not in these paths.
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

#include <fstream>

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


P add(const P& lhs, const P& rhs)
{
	return P(lhs.first + rhs.first, rhs.second);
}


class edge
{
public:
	edge(int x, int y, int z) : t(x), d(y), c(z) {}

	int t, d, c; 

};


class RC
{
public:
	int minCost(int N, vector<VI> M)
	{
		vector<vector<edge> > G(N);

		for (auto& v : M)
		{
			G[v[0] - 1].push_back(edge(v[1] - 1, v[2], v[3]));
			G[v[1] - 1].push_back(edge(v[0] - 1, v[2], v[3]));
		}

		VP dc(N, P(MAXINT/2, MAXINT/2)); dc[0].first = 0, dc[0].second = 0;
		VI prev(N, -1);

		typedef pair<pair<int, int>, int> PW;

		priority_queue<PW, vector<PW>, greater<PW> > que; que.push(PW(P(0, 0), 0));

		while (!que.empty())
		{
			PW pw = que.top(); que.pop();

			int v = pw.second;

			if (dc[v] >= pw.first)
			{
				for (auto& e : G[v])
				{
					if (dc[e.t] > add(dc[v], P(e.d, e.c)))
					{
						dc[e.t] = add(dc[v], P(e.d, e.c));
						que.push(PW(dc[e.t], e.t));
						prev[e.t] = v;
					}
				}
			}
		}

		int ans = 0, i;

		FOR1(i, 1, N)
		{
			for (auto& e : G[prev[i]])
			{
				if (e.t == i)
				{
					ans += e.c;
					break;
				}
			}
		}

		return ans;
	}

};

int main(int argc, char** argv)
{
	RC a;

	ifstream in("test.txt");

	int N, m;

	in >> N >> m;

	vector<VI> G(m);

	int x, i = 0;

	while (in >> x)
	{
		G[(i++)/4].push_back(x);
	}

	cout << a.minCost(N, G) << endl;
	
	return 0;
}
