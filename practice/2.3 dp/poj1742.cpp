/** @file
  * @brief POJ1742 Coins
  * @author malin
  * @date
  * @version 1.0
  * This problem is same to the "multi part sum" problem in page 62 of PCC.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include <fstream>

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


class Coins
{
public:
	int count(VI a, VI c, int m)
	{
		VI dp(m + 1, -1);
		dp[0] = 0;
		
		int i, j;
		
		FOR1(i, 0, a.size())
		{
			FOR1(j, 0, m + 1)
			{
				if (dp[j] >= 0)
				{
					dp[j] = c[i];
				}
				else if (j < a[i] || dp[j - a[i]] <= 0)
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - a[i]] - 1;
				}
			}
		}
		
		int ans = 0;
		
		FOR1(j, 1, m + 1)	// We can spend less time with this method than using the STL function "count_if"
		{
			if ((dp[j] >= 0))
			{
				++ ans;
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	Coins a;
	
	ifstream in("test.txt");
	
	VI A, C;
	
	int n = 0, x;
	while (in >> x)
	{
		++ n;
		if(n <= 100)
		{
			A.push_back(x);
		}
		else
		{
			C.push_back(x);
		}
	}
	
	cout << a.count(A, C, 100000) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

