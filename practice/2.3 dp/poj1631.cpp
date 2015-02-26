/** @file
  * @brief POJ1631 Bridging signals
  * @author malin
  * @date
  * @version 1.0
  * The same to LIS.
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


class BS
{
public:
	int count(VI a)
	{
		VI dp(a.size() + 1, MAXINT);
		
		int i;
		
		FOR1(i, 0, a.size())
		{
			*lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
		}
		
		return lower_bound(dp.begin(), dp.end(), MAXINT) - dp.begin();
	}
	
};

int main(int argc, char* argv[])
{
	BS a;
	
	cout << a.count({5, 8, 9, 2, 3, 1, 7, 4, 6}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

