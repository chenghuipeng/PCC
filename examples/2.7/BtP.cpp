/** @file
  * @brief Bribe the Prisoners
  * @author malin
  * @date 2014年07月16日 星期三 19时24分11秒
  * @version 1.0
  * @note
  * DP
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


class BtP
{
public:
	int minCost(int P, VI Q)
	{
		vector<VI> dp(Q.size() + 1, VI(Q.size() + 2));
		VI A(Q.size() + 2, 0);

		int i, w;

		FOR1(i, 0, Q.size())
		{
			A[i + 1] = Q[i];
		}
		A[A.size() - 1] = P + 1;

		FOR1(i, 0, Q.size() + 1)
		{
			dp[i][i + 1] = 0;
		}

		FOR1(w, 2, Q.size() + 2)
		{
			for (i = 0; i + w <= Q.size() + 1; ++i)
			{
				int j = i + w, t = MAXINT;

				for (int k = i + 1; k != j; ++k)
				{
					t = min(t, dp[i][k] + dp[k][j]);
				}

				dp[i][j] = t + A[j] - A[i] - 2;
			}
		}

		return dp[0][Q.size() + 1];
	}

};


int main(int argc, char** argv)
{
	BtP a;

	cout << a.minCost(20, {3, 6, 14}) << endl;

	return 0;
}
