/** @file
  * @brief POJ3273 Monthly Expense
  * @author malin
  * @date 2014年07月25日 星期五 15时14分26秒
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


class ME
{
public:
	int minMax(VI A, int M)
	{
		a = A; m = M;

		int lb = -1, ub = MAXINT - 1;

		while (ub - lb > 1)
		{
			int mid = (ub + lb)/2;

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
	bool judge(int d)
	{
		int res = 1, s = 0;

		for (auto x : a)
		{
			if (s + x <= d)
			{
				s += x;
			}
			else
			{
				s = x;
				++ res;
			}
		}

		return res <= m;
	}

	VI a;
	int m;

};


int main(int argc, char** argv)
{
	ME a;

	cout << a.minMax({100, 400, 300, 100, 500, 101, 400}, 5) << endl;

	return 0;
}
