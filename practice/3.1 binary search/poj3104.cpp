/** @file
  * @brief POJ3104 Drying
  * @author malin
  * @date 2014年07月25日 星期五 15时37分28秒
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


class Drying
{
public:
	int minTime(VI A, int K)
	{
		a = A; k = K;

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
	bool judge(int t)
	{
		int res = 0;

		for (auto x : a)
		{
			res += ceil(max(0, x - t)/(double)k);
		}

		return res <= t;
	}

	VI a;
	int k;

};


int main(int argc, char** argv)
{
	Drying a;

	cout << a.minTime({2, 3, 9}, 5) << endl;
	return 0;
}
