/** @file
  * @brief POJ1990 MooFest
  * @author malin
  * @date 2014年08月04日 星期一 19时39分35秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "../../examples/3.3/BIT.h"

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


class MF
{
public:
	int solve(VP a)
	{
		int n = a.size();

		VP l;

		sort(a.begin(), a.end());

		for (int i = 0; i != n; ++i)
		{
			l.push_back(P(a[i].second, i));
		}

		sort(l.begin(), l.end());

		BIT bit0(n), bit1(n);

		int ans = 0;

		for (auto p : l)
		{
			int i = p.second;

			int lv = a[i].first*bit1.sum(i) - bit0.sum(i);
			int rv = bit0.sum(n) - bit0.sum(i + 1) - a[i].first*(bit1.sum(n) - bit1.sum(i + 1));

			ans += p.first * (lv + rv);

			bit0.update(i + 1, a[i].first);
			bit1.update(i + 1, 1);
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	MF a;

	cout << a.solve({P(1, 3), P(5, 2), P(6, 2), P(3, 4)}) << endl;

	return 0;
}
