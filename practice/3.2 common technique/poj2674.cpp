/** @file
  * @brief POJ2674 Linear world
  * @author malin
  * @date 2014年08月01日 星期五 14时51分14秒
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


class LW
{
public:
	pair<double, string> solve(double l, double v, VD p, VS d, VS name)
	{
		int n = d.size();
		VD t(n, 0);

		for (int i = 0; i != n; ++i)
		{
			t[i] = (d[i] == "p" ? l - p[i] : p[i])/v;
		}

		double mt = 0; string mname = "";
		for (int i = 0; i != n; ++i)
		{
			if (t[i] > mt)
			{
				mt = t[i];
				mname = name[i];
			}
		}

		return make_pair(mt, mname);
	}

};


int main(int argc, char** argv)
{
	LW a;

	auto ans = a.solve(10, 1, {1, 3, 5, 7}, {"p", "n", "p", "n"}, {"helda", "Joanna", "Venus", "Clever"});

	cout << setiosflags(ios::fixed) << setprecision(2) << ans.first << ' ' << ans.second << endl;

	return 0;
}
