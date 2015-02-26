/** @file
  * @brief POJ2385 Apple Catching
  * @author malin
  * @date
  * @version 1.0
  * @note
  * We define dp[i+1][j+1] is the maximal apples can be catched in the first i minites within j position changing.
  * The recursion formula is:
  * dp[i+1][j=1] = max(dp[i][j], dp[i][j+1]) + (j+1+a[i])%2
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


class AC
{
public:
	int count(VI a, int W)
	{
		vector<VI> dp(a.size() + 1, VI(W + 1, 0));
		dp[0][0] = 0;
		
		int i, j;
		
		FOR1(i, 0, a.size())
		{
			dp[i+1][0] = dp[i][0] + 2 - a[i];
			
			FOR1(j, 0, min(i, W) + 1)
			{
				dp[i+1][j+1] = max(dp[i][j], dp[i][j+1]) + (j+1+a[i])%2;
			}
		}
		
		int ans = 0;
		FOR1(j, 0, W + 1)
		{
			ans = max(ans, dp[a.size()][j]);
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	AC a;
	
	cout << a.count({2, 1, 1, 2, 2, 1, 1}, 2) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

