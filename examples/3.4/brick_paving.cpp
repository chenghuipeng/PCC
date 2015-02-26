/** @file
  * @brief Brack Pave Problem
  * @author malin
  * @date 2014年08月08日 星期五 15时13分24秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <cstring>

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


class BP
{
public:
	int solve(vector<vector<bool> > color, int M)
	{
		int n = color.size(), m = color[0].size();

		int s = 1 << m;

		int dp[2][s];

		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		int* crt = dp[0], *next = dp[1];

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = m - 1; j >= 0; --j)
			{
				for (int used = 0; used != s; ++used)
				{
					// needn't pave (i, j)
					if (used >>j & 1 || color[i][j])
					{
						next[used] = crt[used & ~(1 << j)];
					}
					else
					{
						int cnt = 0;

						// horizontal
						if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1])
						{
							cnt += crt[used | 1 << (j + 1)];
						}

						// vertical
						if (i + 1 < n && !color[i + 1][j])
						{
							cnt += crt[used | 1 << j];
						}

						next[used] = cnt % M;
					}
				}

				swap(crt, next);
			}
		}

		return crt[0];
	}

};


int main(int argc, char** argv)
{
	BP a;

	cout << a.solve({{false, false, false}, {false, true, false}, {false, false, false}}, 10) << endl;
	return 0;
}
