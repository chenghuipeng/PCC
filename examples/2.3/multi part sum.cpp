/** @file
  * @brief multi part sum
  * @author malin
  * @date
  * @version 1.0
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


class MPS
{
public:
	bool solve(VI a, VI m, int K)
	{
		VI dp(K+1, -1);
		dp[0] = 0;
		
		int i, j;
		FOR1(i, 0, a.size())
		{
			FOR1(j, 0, K+1)
			{
				if (dp[j] >= 0)
				{
					dp[j] = m[i];
				}
				else if (j < a[i] || dp[j - a[i]] <= 0)
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - a[i]] - 1;
				}
			}
		}
		
		return dp[K] >= 0;
	}
	
};

int main(int argc, char* argv[])
{
	MPS a;
	
	cout << a.solve({3, 5, 8}, {3, 2, 2}, 17) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

