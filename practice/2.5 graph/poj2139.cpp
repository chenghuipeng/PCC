/** @file
  * @brief POJ2139
  * @author malin
  * @date 2014年07月12日 星期六 15时48分27秒
  * @version 1.0
  * @note
  * A classic problem of Floyd-Warshall.
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


class SDoCB
{
public:
	int minMean(int N, vector<VI> M)
	{
		vector<VI> dp(N, VI(N, MAXINT/2));

		int i, j, k;

		FOR1(i, 0, N) {dp[i][i] = 0;}

		FOR1(i, 0, M.size())
		{
			FOR1(j, 0, M[i].size() - 1)
			{
				FOR1(k, j + 1, M[i].size())
				{
					dp[M[i][j] - 1][M[i][k] - 1] = 1;
					dp[M[i][k] - 1][M[i][j] - 1] = 1;
				}
			}
		}

		FOR1(k, 0, N)
		{
			FOR1(i, 0, N)
			{
				FOR1(j, 0, N)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}

		double ans = MAXINT;

		for (auto& v : dp)
		{
			ans = min(ans, mean(v));
		}

		return 100*ans;
	}

private:
	double mean(VI& v)
	{
		int ans = 0, i = 0;
		for (auto x : v)
		{
			if (x != 0 && x != MAXINT/2)
			{
				ans += x;
				++ i;
			}
		}

		return static_cast<double>(ans)/i;
	}

};

int main(int argc, char** argv)
{
	SDoCB a;

	cout << a.minMean(4, {{1, 2, 3}, {3, 4}}) << endl;

	return 0;
}
