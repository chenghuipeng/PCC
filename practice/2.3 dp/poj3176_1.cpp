/** @file
  * @brief POJ3176 Cow Bowling
  * @author malin
  * @date
  * @version 1.0
  * The recursion formula is dp[i+1][j+1] = max{dp[i][j], dp[i][j+1]} + a[i][j].
  * In order to avoid processing the boundary condition, we add a line with two zero as the first line of dp, 
  * and wealso add a zero at the beginning and end of each line.
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
		vector<VI> dp;
		dp.push_back(VI(2, 0));
		
		int i, j;
		
		FOR1(i, 0, trg.size())
		{
			dp.push_back(VI(trg[i].size() + 2, 0));
			FOR1(j, 0, trg[i].size())
			{
				dp[i+1][j+1] = max(dp[i][j], dp[i][j+1]) + trg[i][j];
			}
		}
		
		int ans = 0;
		FOR1(i, 0, dp[trg.size()].size())
		{
			ans = max(ans, dp[trg.size()][i]);
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

