/** @file
  * @brief POJ3258 River Hopscotch
  * @author malin
  * @date 2014年07月25日 星期五 14时48分44秒
  * @version 1.0
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


class RH
{
public:
	int maxMin(int L, int M, VI A)
	{
		a = A; l = L; m = M;

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
				ub = mid;
			}
		}

		return lb;
	}

private:
	bool judge(int d)
	{
		int res = 0, prev = 0;

		for (auto x : a)
		{
			if (x - prev < d)
			{
				++ res;
			}
			else
			{
				prev = x;
			}
		}

		return res <= m && (l - prev) >= d;
	}

	VI a;
	int l, m;

};


int main(int argc, char** argv)
{
	RH a;

	cout << a.maxMin(25, 2, {2, 14, 11, 21, 17}) << endl;

	return 0;
}
