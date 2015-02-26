/** @file
  * @brief POJ3280 Cheapest Palindrome
  * @author malin
  * @date
  * @version 1.0
  * We define dp[i][j] is the minimal cost to make a[i..j] be palindromic.
  * The recursion formula is:
  * dp[i][j] = min(dp[i+1][j] + min(ac[a[i] - 'a'], dc[a[i] - 'a']), dp[i][j-1] + min(ac[a[j] - 'a'], dc[a[j] - 'a']))						a[i] != a[j]
			 = min(min(dp[i+1][j] + min(ac[a[i] - 'a'], dc[a[i] - 'a']), dp[i][j-1] + min(ac[a[j] - 'a'], dc[a[j] - 'a'])), dp[i+1][j-1])	a[i] == a[j]
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


class CP
{
public:
	int minCost(string a, VI ac, VI dc)
	{
		vector<VI> dp(a.size(), VI(a.size(), 0));
		
		int i, j;
		
		FOR2(i, a.size() - 1, 0)
		{
			dp[i][i] = 0;
			
			FOR1(j, i + 1, a.size())
			{				
				dp[i][j] = min(dp[i+1][j] + min(ac[a[i] - 'a'], dc[a[i] - 'a']),
									dp[i][j-1] + min(ac[a[j] - 'a'], dc[a[j] - 'a']));
				
				if (a[i] == a[j])
				{
					dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
				}
			}
		}
		
		return dp[0][a.size() - 1];
	}
	
};

int main(int argc, char* argv[])
{
	CP a;
	
	VI ac(26, 0); ac[0] = 1000; ac[1] = 350; ac[2] = 200;
	VI dc(26, 0); dc[0] = 1100; dc[1] = 700; dc[2] = 800;
	cout << a.minCost("abcb", ac, dc) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

