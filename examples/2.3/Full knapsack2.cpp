/** @file
  * @brief Full knapsack 
  * @author malin
  * @date
  * @version 2.0
  * @note
  * Using the "array reuse"
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
		VI dp(W+1, 0);
		
		int i, j;
		
		FOR1(i, 0, v.size())
		{
			FOR1(j, w[i], W+1) // We can start with w[i], instead of 0
			{
				dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
			}
		}
			
		return dp[W];
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

