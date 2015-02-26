/** @file
  * @brief POJ2229 Sumsets
  * @author malin
  * @date
  * @version 1.0
  * @note
  * Define dp[i+1][j+1] is different sets' number of j+1 with only using the first i+1 numbers(etc. 1, 2, 4, .. , pow(2,i)
  * The recursion formula is dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j+1-pow(2,i)] 
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


class Sumsets
{
public:
	int count(int N)
	{
		int m = log(N)/log(2) + 1;
		
		vector<VI> dp(m+1, VI(N+1, 0));
		
		int i, j;
		
		FOR1(i, 0, m+1)
		{
			dp[i][0] = 1;
		}
		
		FOR1(i, 0, m)
		{
			FOR1(j, 0, N)
			{
				if (j+1 < pow(2, i))
				{
					dp[i+1][j+1] = dp[i][j+1];
				}
				else
				{
					dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j+1 - pow(2, i)];
				}
			}
		}
		
		for (auto& v : dp)
		{
			for (auto x : v)
			{
				cout << x << ' ';
			}
			cout << endl;
		}
		
		return dp[m][N];
	}
	
};

int main(int argc, char* argv[])
{
	Sumsets a;
	
	cout << a.count(7) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

