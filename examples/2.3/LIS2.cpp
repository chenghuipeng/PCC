/** @file
  * @brief LIS
  * @author malin
  * @date
  * @version 2.0
  * @note
  * Another recurrence, we focus on the minimal end element with same length.
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


class LIS
{
public:
	int lis(VI l)
	{
		VI dp(l.size(), MAXINT);
		
		int i, j;
		FOR1(i, 0, l.size())
		{
			FOR1(j, 0, dp.size())
			{
				*lower_bound(dp.begin(), dp.end(), l[i]) = l[i];
			}
		}
		
		return lower_bound(dp.begin(), dp.end(), MAXINT) - dp.begin();
	}
	
};

int main(int argc, char* argv[])
{
	LIS a;
	
	cout << a.lis({4, 2, 3, 1, 5}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

