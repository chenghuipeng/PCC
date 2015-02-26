/** @file
  * @brief POJ2184 Cow Exhibition
  * @author malin
  * @date
  * @version 1.0
  * We define dp[i][j] is the maximal TS+TF when TS is j and only using the first ith cows.
  * The state transition equation is:
  * dp[i][j] = max{dp[i][j], dp[i][j - s[i]] + s[i] + f[i]}
  */

#include <iostream>
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


class CE
{
public:
	int maxSum(VI s, VI f)
	{
		int N1 = 0, N2 = 0;
		for (auto x : s)
		{
			if (x > 0)
			{
				N1 += x;
			}
			else
			{
				N2 -= x;
			}
		}
							
		vector<VI> dp(2, VI(N1 + N2 + 1, -1));
		dp[0][N2] = 0;
		
		int i, j;
		
		FOR1(i, 0, s.size())
		{
			FOR1(j, 0, N1 + N2 +1)
			{
				dp[(i+1)&1][j] = max(dp[(i+1)&1][j], dp[i&1][j]);
				
				if (dp[i&1][j] >= 0)
				{
					dp[(i+1)&1][j + s[i]] = max(dp[(i+1)&1][j + s[i]], dp[i&1][j] + s[i] + f[i]);
				}
			}
		}
		
		int ans = 0;
		FOR1(j, N2, N1 + N2 + 1)
		{
			if (dp[s.size()&1][j] >= j - N2)
			{
				ans = max(dp[s.size()&1][j], ans);
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	CE a;
	
	cout << a.maxSum({-5, 8, 6, 2, -8}, {7, -6, -3, 1, -5}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

