/** @file
  * @brief POJ2976 Dropping Tests
  * @author malin
  * @date 2014年07月25日 星期五 20时20分24秒
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


class DT
{
public:
	int maxAverage(VI A, VI B, int K)
	{
		a = A; b = B; k = a.size() - K; y.resize(a.size());

		double lb = 0, ub = 2; // The max score is smaller than 1.

		for (int i = 0; i != 10; ++i)
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

		return ub*100;
	}

private:
	bool judge(double m)
	{
		for (int i = 0; i != a.size(); ++i)
		{
			y[i] = a[i] - b[i]*m;
		}

		sort(y.begin(), y.end(), greater<double>());

		double res = 0;

		for (int i = 0; i != k; ++i)
		{
			res += y[i];	
		}

		return res >= 0;
	}

	VD y;
	VI a, b;
	int k;

};


int main(int argc, char** argv)
{
	DT a;

	cout << a.maxAverage({5, 0, 2}, {5, 1, 6}, 1) << endl;

	return 0;
}
