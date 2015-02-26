/** @file
  * @brief POJ2392 Space Elevator
  * @author malin
  * @date
  * @version 1.0
  * The same to the "multi sum part" in PCC page62. 
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


class SE
{
public:
	int maxHeight(vector<VI> a)
	{
		sort(a.begin(), a.end(),
				[](const VI& lhs, const VI& rhs){return lhs[1] < rhs[1];});
			
		VI dp((*max_element(a.begin(), a.end(), [](const VI& lhs, const VI& rhs){return lhs[1] < rhs[1];}))[1] + 1, -1);
		
		dp[0] = 0;
		
		int i, j;
		
		FOR1(i, 0, a.size())
		{
			FOR1(j, 0, dp.size())
			{
				if (dp[j] >= 0)
				{
					dp[j] = a[i][2];
				}
				else if (j < a[i][0] || j > a[i][1] || dp[j-a[i][0]] <= 0)
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j-a[i][0]] - 1;
				}
			}
		}
		
		int ans;
		FOR2(ans, dp.size() - 1, 0)
		{
			if (dp[ans] >= 0)
			{
				break;
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	SE a;
	
	cout << a.maxHeight({{5, 11, 3}, {8, 12, 2}}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

