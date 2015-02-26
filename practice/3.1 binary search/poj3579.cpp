/** @file
  * @brief POJ3579 Median
  * @author malin
  * @date 2014年07月27日 星期日 15时50分35秒
  * @version 1.0
  * @note
  * The complexity is log(1,000,000,000)*log(N).
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

class Median
{
public:
	int median(VI A)
	{
		a =A; num = (ll)a.size()*(a.size() - 1)/2;

		num = (num & 1 == 0) ? num/2 : num/2 + 1;

		sort(a.begin(), a.end());

		int lb = -1, ub = MAXINT - 1;

		while (ub - lb > 1)
		{
			int mid = (ub + lb)/2;

			if (judge(mid))
			{
				lb = mid;
			}
			else
			{
				ub =mid;
			}
		}

		return lb;
	}

private:
	bool judge(int m)
	{
		ll cnt = 0;

		for (auto itr = a.begin(); itr != a.end(); ++itr)
		{
			cnt += a.end() - lower_bound(a.begin(), a.end(), *itr + m);
		}

		return cnt >= num;
	}

	VI a;
	ll num;

};


int main(int argc, char** argv)
{
	Median a;

	cout << a.median({1, 3, 2, 4}) << endl;
	return 0;
}
