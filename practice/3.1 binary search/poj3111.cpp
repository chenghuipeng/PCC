/** @file
  * @brief POJ3111 K Best
  * @author malin
  * @date 2014年07月25日 星期五 20时51分11秒
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


class KB
{
public:
	VI kBest(VP A, int K)
	{
		a = A; k = K; y.resize(a.size()); ans.resize(k);

		double lb = 0, ub = 2;

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

		return move(ans);
	}

private:
	bool judge(double m)
	{
		for (int i = 0; i != a.size(); ++i)
		{
			y[i].first = a[i].first - a[i].second*m;
			y[i].second = i;
		}

		sort(y.begin(), y.end(), greater<pair<double, int> >());

		double res = 0;

		for (int i = 0; i != k; ++i)
		{
			res += y[i].first;
		}

		if (res >= 0)
		{
			for (int i = 0; i != k; ++i)
			{
				ans[i] = y[i].second;
			}
		}

		return res >= 0;
	}

	VP a;
	int k;
	vector<pair<double, int> > y;
	VI ans;

};


int main(int argc, char** argv)
{
	KB a;

	auto ans = a.kBest({P(1, 1), P(1, 2), P(1, 3)}, 2);

	for (auto x : ans)
	{
		cout << x + 1 << ' ';
	}
	cout << endl;

	return 0;
}
