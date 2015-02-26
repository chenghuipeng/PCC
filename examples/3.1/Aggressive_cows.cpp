/** @file
  * @brief Aggressive cows
  * @author malin
  * @date 2014年07月24日 星期四 17时00分05秒
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


class AC
{
public:
	int maxMin(VI A, int M)
	{
		a = A; m = M;

		sort(a.begin(), a.end());

		int lb = -1, ub = 10e8 + 1;

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
		int cnt = 1, s = 0;

		for (int i = 1; i != a.size(); ++i)
		{
			if (a[i] - a[s] >= d)
			{
				s = i;
				++ cnt;
			}
		}

		return cnt >= m;
	}

	VI a;
	int m;

};


int main(int argc, char** argv)
{
	AC a;

	cout << a.maxMin({1, 2, 8, 4, 9}, 3) << endl;

	return 0;
}
