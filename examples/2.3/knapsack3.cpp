/** @file
  * @brief 0-1 Packets
  * @author malin
  * @date
  * @version 3.0
  * @note
  * Using the state transition method.
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


class Knapsack
{
public:
	int maxValue(VI w, VI v, int W)
	{
		vector<VI> dp(v.size() + 1, VI(W+1, 0));
		
		int i, j;
		FOR1(i, 0, v.size())
		{
			FOR1(j, 0, W + 1)
			{
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);	// transfer to the dp[i+1][j]
				
				if (j + w[i] <= W)
				{
					dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]); // transfer to the dp[i+1][j+w[i]]
				}
			}
		}
		
		return dp[v.size()][W];
	}
	
};

int main(int argc, char* argv[])
{
	Knapsack a;
	
	cout << a.maxValue({2, 1, 3, 2}, {3, 2, 4, 2}, 5) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

