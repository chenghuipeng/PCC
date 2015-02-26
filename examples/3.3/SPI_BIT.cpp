/** @file
  * @brief A Simple Problem with Integers
  * @author malin
  * @date 2014年08月04日 星期一 11时08分58秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "BIT.h"

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


class SPI
{
public:
	void solve(VI A, vector<char> T, VI L, VI R, VI X)
	{
		int n = A.size();

		BIT b0(n), b1(n);

		for (int i = 0; i != n; ++i)
		{
			b0.update(i + 1, A[i]);
		}

		for (int i = 0; i != T.size(); ++i)
		{
			int l = L[i], r = R[i], x = X[i];

			if (T[i] == 'C')
			{
				b0.update(l, -x * (l - 1));
				b1.update(l, x);
				b0.update(r + 1, r * x);
				b1.update(r + 1, -x);
			}
			else
			{
				int ls = b0.sum(l - 1) + b1.sum(l - 1) * (l - 1);
				int rs = b0.sum(r) + b1.sum(r) * r;

				cout << rs - ls << endl;
			}
		}
	}

};


int main(int argc, char** argv)
{
	SPI a;

	a.solve({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {'Q', 'Q', 'Q', 'C', 'Q'}, {4, 1, 2, 3, 2}, {4, 10, 4, 6, 4}, {0, 0, 0, 3, 0});

	return 0;
}
