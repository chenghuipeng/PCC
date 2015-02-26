/** @file
  * @brief POJ3046 Ant Counting
  * @author malin
  * @date
  * @version 1.0
  * The same to complete knapsack problem.
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
	int count(int T, int S, int B, VI A)
	{
		VI a(T, 0);
		
		for (auto x : A)
		{
			++ a[x-1];
		}
		
		vector<VI> dp(2, VI(B+1, 0));
		
		int i, j;
		
		dp[0][0] = dp[1][0] = 1;
		
		FOR1(i, 0, T)
		{
			FOR1(j, 1, B + 1)
			{
				if (j - 1 >= a[i])
				{
					dp[(i + 1) & 1][j] = (dp[(i + 1) & 1][j - 1] + dp[i & 1][j] - dp[i & 1][j - 1 - a[i]] + 1000000)%1000000;
				}
				else
				{
					dp[(i + 1) & 1][j] = (dp[(i + 1) & 1][j - 1] + dp[i & 1][j])%1000000;
				}
			}
		}
		
		int ans = 0;
		
		FOR1(j, S, B + 1)
		{
			ans += dp[T & 1][j];
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	AC a;
	
	cout << a.count(3, 2, 3, {1, 2, 2, 1, 3}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

