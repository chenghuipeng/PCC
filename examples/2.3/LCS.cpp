/** @file
  * @brief LCS
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


class LCS
{
public:
	int lcs(string s, string t)
	{
		vector<VI> dp(s.size()+1, VI(t.size()+1, 0));
		
		int i, j;
		
		FOR1(i, 0, s.size())
		{
			FOR1(j, 0, t.size())
			{
				if (s[i] == t[j])
				{
					dp[i+1][j+1] = dp[i][j] + 1;
				}
				else
				{
					dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
				}
			}
		}
		
		return dp[s.size()][t.size()];
	}
	
};

int main(int argc, char* argv[])
{
	LCS a;
	
	cout << a.lcs("abcd", "becd") << endl;
	
	return 0;
}

/**
  * just for convenient
  */

