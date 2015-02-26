/** @file
  * @brief POJ3264 Balanced LineUp
  * @author malin
  * @date 2014年08月06日 星期三 16时30分12秒
  * @version 1.0
  * @note
  *	In this version, we use the segment tree. The complicity is Q*log(N)
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


class ST
{
public:
	ST(int n_)
	{
		n = 1;

		while (n < n_) n *= 2;

		array.assign(2 * n - 1, P(MAXINT, 0));
	}

	// k is 0-indexed
	void update(int k, int x)
	{
		k += n - 1;

		array[k].first = array[k].second = x;

		while (k > 0)
		{
			k = (k - 1)/2;

			array[k].first = min(array[2*k + 1].first, array[2*k + 2].first);
			array[k].second = max(array[2*k + 1].second, array[2*k + 2].second);
		}
	}

	// return the minimum and maximum in [a, b)
	P query(int a, int b, int k, int l, int r)
	{
		if (a <= l && r <= b)
		{
			return array[k];
		}
		else if (a < r && l < b)
		{
			P p1 = query(a, b, 2*k + 1, l, (l + r)/2), p2 = query(a, b, 2*k + 2, (l + r)/2, r);

			return P(min(p1.first, p2.first), max(p1.second, p2.second));
		}
		else
		{
			return P(MAXINT, 0);
		}
	}

private:
	int n;
	VP array;

};


class BL
{
public:
	void solve(VI h, VP range)
	{
		int n = h.size();

		ST st(n);

		for(int i = 0; i != n; ++i)
		{
			st.update(i, h[i]);
		}

		for (auto& p : range)
		{
			int a = p.first - 1, b = p.second;

			P ans = st.query(a, b, 0, 0, n);

			cout << ans.second - ans.first << endl;
		}
	}

};


int main(int argc, char** argv)
{
	BL a;

	a.solve({1, 7, 3, 4, 2, 5}, {P(1, 5), P(4, 6), P(2, 2)});

	return 0;
}
