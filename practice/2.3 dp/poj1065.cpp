/** @file
  * @brief POJ1065 Wooden Sticks
  * @author malin
  * @date
  * @version 1.0
  * @note
  * We can proove that the number of increasing subsequence is equal to the length of longest decreasing subsequence.
  * First, we proove that a increasing subsequence includes at most one element of LDS;
  * Second, we proove that a increasing subsequence includes at least one element of LDS.
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


class WS
{
public:
	int count(VP w)
	{
		sort(w.begin(), w.end());
		
		VI dp(w.size() + 1, -1);
		
		int i;
		
		FOR1(i, 0, w.size())
		{
			*lower_bound(dp.begin(), dp.end(), w[i].second, greater<int>()) = w[i].second;
		}
		
		for (auto x : dp) cout << x << ' ';
		cout << endl;
		
		return lower_bound(dp.begin(), dp.end(), -1, greater<int>()) - dp.begin();
	}
	
};

int main(int argc, char* argv[])
{
	WS a;
	
	cout << a.count({P(1, 3), P(2, 2), P(3, 1)}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

