/** @file
  * @brief AOJ2224 Save your cat
  * @author malin
  * @date 2014年07月13日 星期日 16时52分39秒
  * @version 1.0
  * The same to POJ2377.
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


class edge
{
public:
	edge(int a, double b) : t(a), c(b) {}

	int t;
	double c;

};


class SYC
{
public:
	double minCost(int N, vector<VI> C, vector<VI> M)
	{
		vector<vector<edge> > G(N);

		double ans = 0;

		for (auto& v : M)
		{
			int a = v[0] - 1, b = v[1] - 1;
			double d = sqrt(pow(C[a][0] - C[b][0], 2) + pow(C[a][1] - C[b][1], 2));

			ans += d;
			
			G[a].push_back(edge(b, d));
			G[b].push_back(edge(a, d));
		}

		VD d(N, -1); d[0] = 0.0;

		typedef pair<double, int> PD;

		priority_queue<PD> que;

		for (int i = 0; i != N; ++i)
		{
			if (d[i] == -1)
			{
				d[i] = 0;
				que.push(PD(0, i));

				while (!que.empty())
				{
					PD p = que.top(); que.pop();
		
					int v = p.second;

					if (d[v] <= p.first && d[v] != -2)
					{
						ans -= p.first;

						d[v] = -2;

						for (auto& e : G[v])
						{
							if (d[e.t] < e.c && d[e.t] != -2)
							{
								d[e.t] = e.c;
								que.push(PD(e.c, e.t));
							}
						}
					}
				}
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	SYC a;

	ifstream in("test.txt");

	int N, m;

	in >> N >> m;

	vector<VI> C(N), M(m);

	int i = 0, x;

	while (in >> x)
	{
		if (i < 2*N)
		{
			C[(i++)/2].push_back(x);
		}
		else
		{
			M[((i++) - 2*N)/2].push_back(x);
		}
	}


	cout << a.minCost(N, C, M) << endl;

	return 0;
}
