/** @file
  * @brief POJ3666 Making the Grade
  * @author malin
  * @date
  * @version 1.0
  * @note
  * The main idea is that all of the final elevations are the subset of the initial elevations.
  * Define dp[i][j] is the minimal cost when the ith number is the jth high elevation.
  * The recursion formula is:
  * dp[i][j] = min{dp[i-1][k]} + abs(a[i] - oa[j]) 0 <= k <= j
  			 = min{dp[i-1][j], dp[i][j-1] - abs(a[i] - oa[j-1])} + abs(a[i] - oa[j])
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


class MtG
{
public:
	int count(VI a)
	{
		VI oa = a;
		
		sort(oa.begin(), oa.end());
		
		oa.erase(unique(oa.begin(), oa.end()), oa.end());
		
		vector<VI> dp1(2, VI(oa.size(), 0)), dp2(2, VI(oa.size(), 0));
		
		int i, j, k;
		
		FOR1(j, 0, oa.size())
		{
			dp1[0][j] = dp2[0][j] = abs(a[0] - oa[j]);
		}
		
		FOR1(i, 1, a.size())
		{
			dp1[i&1][0] = abs(a[i] - oa[0]) + dp1[(i-1)&1][0];
			dp2[i&1][oa.size()-1] = abs(a[i] - oa[oa.size()-1]) + dp2[(i-1)&1][oa.size()-1];
			FOR1(j, 1, oa.size())
			{
				dp1[i&1][j] = min(dp1[(i-1)&1][j], dp1[i&1][j-1] - abs(a[i] - oa[j-1])) + abs(a[i] - oa[j]);
			}
			FOR2(k, oa.size() - 2, 0)
			{
				dp2[i&1][k] = min(dp2[(i-1)&1][j], dp2[i&1][j+1] - abs(a[i] - oa[j+1])) + abs(a[i] - oa[j]);
			}
		}
		
		int ans = MAXINT;
		FOR1(j, 0, oa.size())
		{
			ans = min(ans, min(dp1[(a.size() - 1)&1][j], dp2[(a.size() - 1)&1][j]));
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	MtG a;
	
	cout << a.count({1, 3, 2, 4, 5, 3, 9}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

