/** @file
  * @brief partition numbers
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


class PN
{
public:
	int count(int n, int m, int M)
	{
		vector<VI> dp(m+1, VI(n+1, 0));
		dp[0][0] = 1;
		
		int i, j;
		FOR1(i, 1, m+1)
		{
			FOR1(j, 0, n+1)
			{
				dp[i][j] = dp[i-1][j];
				
				if (j >= i)
				{
					dp[i][j] += dp[i][j-i];
				}
				
				dp[i][j] %= M;
			}
		}
		
		return dp[m][n];
	}
	
};

int main(int argc, char* argv[])
{
	PN a;
	
	cout << a.count(4, 3, 10000) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

