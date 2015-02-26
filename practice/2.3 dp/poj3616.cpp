/** @file POJ3616 Milking Time
  * @brief
  * @author malin
  * @date
  * @version 1.0
  * @note
  * We define dp[i+1] is the maximum number when interval i is the last interval if the interval is selected.
  * The recursion formula is:
  * dp[i+1] = max(dp[i+1], dp[i] + e[i])												s[i] >= t[i-1] + R
  *			= max(dp[i+1], max(dp[i] - a[j-1][2] + max(a[i][2], a[j-1][2]))(0<j<=i))	s[i] < t[i-1] + R
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


class MT
{
public:
	int count(int N, int R, vector<VI> a)
	{
		sort(a.begin(), a.end(),
			[](const VI& lhs, const VI& rhs){return lhs[0] < rhs[0];});
		
		int M = a.size();
		VI dp(M+1, 0);
		dp[1] = a[0][2];
		
		int i, j, ans = dp[1];
		
		FOR1(i, 1, M)
		{
			FOR1(j, 1, i + 1)
			{
				if (a[i][0] >= a[j-1][1] + R)
				{
					dp[i+1] = max(dp[i+1], dp[j] + a[i][2]);
				}
				else
				{
					dp[i+1] = max(dp[i+1], dp[i] - a[j-1][2] + max(a[i][2], a[j-1][2]));
				}
			}
			
			ans = max(ans, dp[i+1]);
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	MT a;
	
	cout << a.count(12, 2, {{1, 2, 8}, {10, 12, 19}, {3, 6, 24}, {7, 10, 31}}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

