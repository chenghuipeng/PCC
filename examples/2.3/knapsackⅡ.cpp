/** @file
  * @brief knapsack¢ò
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


class Knapsack
{
public:
	int maxValue(VI w, VI v, int W)
	{
		int V = accumulate(v.begin(), v.end(), 0);
		VI dp(V + 1, MAXINT/2);
		dp[0] = 0;
		
		int i, j;
		
		FOR1(i, 0, v.size())
		{
			FOR2(j, V, v[i]) // If we want to reuse the array,  we must process "j" in reverse.
			{
				dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
			}
		}
		
		int ans = 0;
		FOR1(i, 0, V+1)
		{
			if (dp[i] <= W) ans = i;
		}
		
		return  ans;
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

