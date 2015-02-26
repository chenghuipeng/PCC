/** @file
  * @brief Max Average
  * @author malin
  * @date 2014年07月25日 星期五 11时02分18秒
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


class MA
{
public:
	double maxAverage(VP A, int K)
	{
		a = A; k = K; y.resize(a.size());

		double lb = 0, ub = 1000001;

		for (int i = 0; i != 100; ++i)
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
	bool judge(double m)
	{
		for (int i = 0; i != a.size(); ++i)
		{
			y[i] = a[i].second - m*a[i].first;
		}

		sort(y.begin(), y.end(), greater<double>());

		double res = 0;

		for (int i = 0; i != k; ++i)
		{
			res += y[i];
		}

		return res >= 0.0;
	}

	VP a;
	int k;
	VD y;

};


int main(int argc, char** argv)
{
	MA a;

	cout << a.maxAverage({P(2, 2), P(5, 3), P(2, 1)}, 2) << endl;
	return 0;
}
