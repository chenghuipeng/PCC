/** @file
  * @brief multi set number
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


class MSN
{
public:
	int count(VI a, int m, int M)
	{
		int n = a.size();
		
		vector<VI> dp(n+1, VI(m+1, 0));
		
		int i, j;
		
		FOR1(i, 0, n+1) dp[i][0] = 1;
		
		FOR1(i, 0, n)
		{
			FOR1(j, 1, m+1)
			{
				if (j > a[i])
				{
					dp[i+1][j] = (dp[i][j] + dp[i+1][j-1] - dp[i][j-1-a[i]])%M;
				}
				else
				{
					dp[i+1][j] = (dp[i][j] + dp[i+1][j-1])%M;
				}
			}
		}
		
		return dp[n][m];
	}
	
};

int main(int argc, char* argv[])
{
	MSN a;
	
	cout << a.count({1, 2, 3}, 3, 10000) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

