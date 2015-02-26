/** @file
  * @brief LIS
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


class LIS
{
public:
	int lis(VI l)
	{
		VI dp(l.size(), 1);
		
		int i, j, ans = 0;
		FOR1(i, 0, l.size())
		{
			FOR1(j, 0, i)
			{
				if (l[j] < l[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			
			ans = max(ans, dp[i]); // We can find the best answer at this loop
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	LIS a;
	
	cout << a.lis({4, 2, 3, 1, 5}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

