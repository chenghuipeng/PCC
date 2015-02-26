/** @file
  * @brief POJ3292 Semi-prime H-numbers
  * @author malin
  * @date 2014年07月15日 星期二 11时19分01秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
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


class SPH
{
public:
	int count(int n)
	{
		VI ph;

		vector<bool> is_ph(n + 1, true);

		for (int i = 5; i <= n; i += 4)
		{
			if (is_ph[i])
			{
				for (int j = 2*i; j <= n; j += i)
				{
					is_ph[j] = false;
				}

				ph.push_back(i);
			}
		}

		int ans = 0;

		int i, j;

		set<int> sph;

		FOR1(i, 0, ph.size())
		{
			FOR1(j, i, ph.size())
			{
				int m = ph[i]*ph[j];

				if (m > n) break;

				if (sph.find(m) == sph.end())
				{
					++ ans;
					sph.insert(m);
				}
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	SPH a;

	cout << a.count(789) << endl;
	return 0;
}
