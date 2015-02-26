/** @file
  * @brief Minimum Scalar Product
  * @author malin
  * @date 2014年07月16日 星期三 17时29分49秒
  * @version 1.0
  * @note
  * greedy selection
  */

#include<iostream>
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

typedef long long ll;

class MSP
{
public:
	ll product(VI x, VI y)
	{
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<int>());

		ll ans = 0;

		for (int i = 0; i != x.size(); ++i)
		{
			ans += (ll)x[i] * y[i];
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	MSP a;

	cout << a.product({1, 2, 3, 4, 5}, {1, 0, 1, 0, 1}) << endl;

	return 0;
}
