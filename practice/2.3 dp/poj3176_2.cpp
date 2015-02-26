/** @file
  * @brief POJ3176 Cow Bowling
  * @author malin
  * @date
  * @version 2.0
  * In this version, we use a linear array instead of the dyadic array
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


class CB
{
public:
	int maxSum(vector<VI> trg)
	{
		VI dp(350, 0);
		
		int i, j;
		
		FOR1(i, 0, trg.size())
		{
			FOR2(j, trg[i].size() - 1, 0)
			{
				dp[j+1] = max(dp[j], dp[j+1]) + trg[i][j];
			}
		}
		
		int ans = 0;
		FOR1(i, 0, dp.size())
		{
			ans = max(ans, dp[i]);
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	CB a;
	
	cout << a.maxSum({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
	 
	return 0;
}

/**
  * just for convenient
  */

