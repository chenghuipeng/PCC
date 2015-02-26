/** @file
  * @brief TSP
  * @author malin
  * @date 2014年08月08日 星期五 09时49分04秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

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


class TSP
{
public:
	int solve(vector<VI> G)
	{
		int n = G.size(), s = 1 << n;

		vector<VI> dp(s, VI(n, MAXINT/2));

		dp[s - 1][0] = 0;

		for (int i = s - 2; i >= 0; --i)
		{
			for (int v = 0; v != n; ++v)
			{
				for (int u = 0; u != n; ++u)
				{
					if (!(i >> u & 1))
					{
						dp[i][v] = min(dp[i][v], dp[i | 1 << u][u] + G[v][u]);
					}
				}
			}
		}

		return dp[0][0];
	}

};


int main(int argc, char** argv)
{
	TSP a;

	cout << a.solve({{0, 3, MAXINT/2, 4, MAXINT/2}, {MAXINT/2, 0, 5, MAXINT/2, MAXINT/2, MAXINT/2}, 
			{4, MAXINT/2, 0, 5, MAXINT/2}, {MAXINT/2, MAXINT/2, MAXINT/2, 0, 3}, {7, 6, MAXINT/2, MAXINT/2, 0}}) << endl;

	return 0;
}
