/** @file
  * @brief POJ2010 Moo University - Financial Aid
  * @author malin
  * @date 2014年07月28日 星期一 11时28分50秒
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


class Median
{
public:
	int maxMedian(VP A, int N, int F)
	{
		a = A; n = N; f = F;

		sort(a.begin(), a.end());

		int lb = -1, ub = a.size();

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

		return a[lb].first;
	}

private:
	bool judge(int m)
	{
		VP aa = a;

		auto pred = [](const P& lhs, const P& rhs){return lhs.second < rhs.second;};

		sort(aa.begin(), aa.begin() + m, pred);
		sort(aa.begin() + m + 1, aa.end(), pred);

		int res = aa[m].second;

		for (int i = 0; i != n/2; ++i)
		{
			res += aa[i].second + aa[m + i + 1].second;
		}

		return res <= f;
	}

	VP a;
	int n, f;

};


int main(int argc, char** argv)
{
	Median a;

	cout << a.maxMedian({P(30, 25), P(50, 21), P(20, 20), P(5, 18), P(35, 30)}, 3, 70) << endl;

	return 0;
}
