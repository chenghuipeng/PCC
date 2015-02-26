/** @file
  * @brief POJ3685 Matrix
  * @author malin
  * @date 2014年07月27日 星期日 16时30分17秒
  * @version 1.0
  */

#include<iostream>
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


typedef long long ll;

class Matrix
{
public:
	ll kMedian(int N, ll M)
	{
		n = N; m = M;

		ll lb = -3000000000, ub = 8000000000;

		while (ub - lb > 1)
		{
			ll mid = (ub + lb)/2;

			if (judge(mid))
			{
				ub = mid;
			}
			else
			{
				lb = mid;
			}
		}

		return ub;
	}

private:
	bool judge(ll x)
	{
		ll cnt = 0;
		for (int j = 1; j <= n; ++j)
		{
			ll cons = x - ((ll)j*j - (ll)100000*j);

			int lb = 0, ub = n + 1;

			while (ub - lb > 1)
			{
				ll mid = (ub + lb)/2;

				if (mid*mid + 100000*mid + j*mid <= cons)
				{
					lb = mid;
				}
				else
				{
					ub = mid;
				}
			}

			cnt += lb;
		}

		return cnt >= m;
	}

	int n;
	ll m;

};


int main(int argc, char** argv)
{
	Matrix a;

	cout << a.kMedian(48888, 2000000000) << endl;

	return 0;
}
