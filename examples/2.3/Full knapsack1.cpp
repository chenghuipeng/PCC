/** @file
  * @brief Full knapsack 
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


class FullKnapsack
{
public:
	int maxValue(VI w, VI v, int W)
	{
		vector<VI> dp(v.size()+1, VI(W+1, 0));
		
		int i, j;
		
		FOR1(i, 0, v.size())
		{
			FOR1(j, 0, W+1)
			{
				if (j < w[i])
				{
					dp[i+1][j] = dp[i][j];
				}
				else
				{
					dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]] + v[i]);
				}
			}
		}
			
		return dp[v.size()][W];
	}
	
};

int main(int argc, char* argv[])
{
	FullKnapsack a;
	
	cout << a.maxValue({3, 4, 2}, {4, 5, 3}, 7) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

