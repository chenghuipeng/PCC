/** @file
  * @brief Travelling by Stagecoach
  * @author malin
  * @date 2014年08月08日 星期五 10时34分34秒
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


const int INF = MAXINT/2;

class TS
{
public:
	void solve(int a, int b, int m, VI t, vector<VI> G)
	{
		int n = t.size(), s = 1 << n;

		-- a; -- b;

		vector<VD> dp(s, VD(m, (double)INF));

		dp[s - 1][a] = 0;

		double ans = (double)INF;

		for (int i = s - 1; i >= 0; --i)
		{
			for (int v = 0; v != m; ++v)
			{
				for (int u = 0; u != m; ++u)
				{
					for (int j = 0; j != n; ++j)
					{
						if (i >> j & 1)
						{
							dp[i & ~(1 << j)][u] = min(dp[i & ~(1 << j)][u], dp[i][v] + G[v][u]/(double)t[j]);
						}
					}
				}
			}

			ans = min(ans, dp[i][b]);
		}

		if (ans == MAXINT) cout << "Impossible" << endl;
		else cout << ans << endl;
	}

};


int main(int argc, char** argv)
{
	TS a;

	a.solve(2, 1, 4, {3, 1}, {{0, INF, 3, 2}, {INF, 0, 3, 5}, {3, 3, 0, INF}, {2, 5, INF, 0}});

	return 0;
}
