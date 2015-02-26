/** @file
  * @brief Cable master
  * @author malin
  * @date 2014年07月24日 星期四 10时48分57秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include <iomanip>

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


class CM
{
public:
	double maxLength(VD L, int K)
	{
		l = L; k = K;

		double lb = 0, ub = 100001; // According to the problem station, the cables' length is shorter than 100000.

		for (int i = 0; i != 100; ++ i)
		{
			double mid = (ub + lb)/2;

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
	bool judge(double a)
	{
		int res = 0;

		for (auto x : l)
		{
			res += floor(x/a);
		}

		return res >= k;
	}

	VD l;
	int k;

};


int main(int argc, char** argv)
{
	CM a;

	cout.setf(ios::fixed);

	cout << std::setprecision(2) << a.maxLength({8.02, 7.43, 4.57, 5.39}, 11) << endl;

	return 0;
}
