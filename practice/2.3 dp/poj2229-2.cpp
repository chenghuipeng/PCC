/** @file
  * @brief POJ2229 Sumsets
  * @author malin
  * @date
  * @version 1.0
  * @note
  * Another recursion formula:
  * dp[i] = dp[i-1]				i is odd number
  *       = dp[i-2] + dp[i/2]	i is even number
  * if i is odd, it must has a "1"; if i is even, it must has either two "1" or zer "1", and it has no "1", we can let
  * every number be devided by 2.
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


class Sumsets
{
public:
	int count(int N)
	{
		VI dp(N+1);
		
		dp[0] = 0; dp[1] = 1; dp[2] = 2;
		
		int i;
		FOR1(i, 2, N)
		{
			if (i%2 == 0)
			{
				dp[i+1] = dp[i-1] + dp[i/2];
			}
			else
			{
				dp[i+1] = dp[i];
			}
		}
		
		return dp[N];
	}
	
};

int main(int argc, char* argv[])
{
	Sumsets a;
	
	cout << a.count(7) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

