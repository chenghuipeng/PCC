/** @file
  * @brief POJ1258 Agri-Net
  * @author malin
  * @date 2014年07月13日 星期日 14时47分57秒
  * @version 1.0
  * A direct use of MST. As the number of vertices is smaller than 100, so we can use kruskal for simple.
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "../../examples/2.4/UF.h"

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
	edge(int x, int y, int z) : f(x), t(y), c(z) {}

	int f, t, c;

};


class AN
{
public:
	int minCost(int N, vector<VI> M)
	{
		vector<edge> G; G.reserve(N*N);

		int i, j;

		FOR1(i, 0, N)
		{
			FOR1(j, 0, i)
			{
				if (M[i][j] != 0)
				{
					G.push_back(edge(i, j, M[i][j]));
				}
			}
		}

		UF<int> uf(N);

		sort(G.begin(), G.end(), [](const edge& lhs, const edge& rhs){return lhs.c < rhs.c;});

		int ans = 0;

		for (auto& e : G)
		{
			if (!uf.same(e.f, e.t))
			{
				ans += e.c;
				uf.unite(e.f, e.t);
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	AN a;

	cout << a.minCost(4, {{0, 4, 9, 21}, {4, 0, 8, 17}, {9, 8, 0, 16}, {21, 17, 16, 0}}) << endl;
	
	return 0;
}
