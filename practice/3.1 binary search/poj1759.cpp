/** @file
  * @brief POJ1759 Garland
  * @author malin
  * @date 2014年07月28日 星期一 21时29分25秒
  * @version 1.0
  * @note
  * H2 = ((N-2)*A + B)/(N-1) - (N-2).
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


class Garland
{
public:
	double minB(double A, int N)
	{
		a = A; n = N;

		double lb = 0, ub = 10e10;

		for (int i = 0; i != 100; ++i)
		{
			double mid = (ub + lb)/2.0;

			if (judge(mid))
			{
				ub = mid;
			}
			else
			{
				lb = mid;
			}
		}

		return floor(ub*100)/100.0;
	}

private:
	bool judge(double b)
	{
		double h = ((n - 2)*a + b)/(n - 1) - (n - 2), mh = h, prevh = a;

		for (int i = 0; i != n - 3; ++i)
		{
			double tmp = 2*(h + 1) - prevh;
			prevh = h;
			h = tmp;
			mh = min(mh, h);
		}

		return mh >= 0;
	}

	double a;
	int n;

};


int main(int argc, char** argv)
{
	Garland a;

	cout.setf(ios::fixed);

	cout << setprecision(2) << a.minB(532.81, 692) << endl;
	return 0;
}
