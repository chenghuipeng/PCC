/** @file
  * @brief Jessica's Reading Problem
  * @author malin
  * @date 2014年07月29日 星期二 15时31分34秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

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


class JRP
{
public:
	int solve(VI a)
	{
		set<int> all;
		map<int, int> count;

		int i = 0;

		FOR1(i, 0, a.size())
		{
			all.insert(a[i]);
		}

		int s = 0, t = 0, num = 0, n = all.size(), ans = n + 1;

		while (true)
		{
			while (num < n && t < n)
			{
				if (count[a[t++]] ++ == 0)
				{
					++ num;
				}
			}

			if (num < n) break;

			do
			{
				-- count[a[s]];
			}
			while (count[a[s++]] > 0);

			-- num;

			ans = min(ans, t - s + 1);
		}

		return ans <= n ? ans : 0;
	}

};


int main(int argc, char** argv)
{
	JRP a;

	cout << a.solve({1, 8, 8, 8, 1}) << endl;

	return 0;
}
