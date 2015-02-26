/** @file
  * @brief POJ3368 Frequent values
  * @author malin
  * @date 2014年08月06日 星期三 17时21分06秒
  * @version 1.0
  * @note
  * Using segment tree
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

		li.assign(2*n - 1, P(MAXINT, 0));
		mi.assign(2*n - 1, P(MAXINT, 0));
		ri.assign(2*n - 1, P(MAXINT, 0));
	}

	void update(int k, int x)
	{
		k += n - 1;

		li[k].first = mi[k].first = ri[k].first = x;
		li[k].second = mi[k].second = ri[k].second = 1;

		while (k > 0)
		{
			k = (k - 1)/2;

			li[k] = li[2*k + 1].first == MAXINT ? li[2*k + 2] : li[2*k + 1];
			ri[k] = ri[2*k + 2].first == MAXINT ? ri[2*k + 1] : ri[2*k + 2];

			if (li[k].first == ri[k].first)
			{
				li[k].second = ri[k].second = li[k].second + ri[k].second;
			}

			if (ri[2*k + 1].first == li[2*k + 2].first && ri[2*k + 1].first != MAXINT)
			{
				mi[k] = maxP(mi[k], P(ri[2*k + 1].first, ri[2*k + 1].second + li[2*k + 2].second));

				if (li[2*k + 1].first == ri[2*k + 1].first)
				{
					li[k].second += li[2*k + 1].second + li[2*k + 2].second;
				}

				if (ri[2*k + 2].first == li[2*k + 2].first)
				{
					ri[k].second = ri[2*k + 1].second + ri[2*k + 2].second;
				}
			}

			mi[k] = maxP(mi[k], mi[2*k + 1]);
			mi[k] = maxP(mi[k], mi[2*k + 2]);

			if (li[k].first == mi[k].first) li[k].second = mi[k].second;
			if (ri[k].first == mi[k].first) ri[k].second = mi[k].second;
		}
	}

	VP query(int a, int b, int k, int l, int r)
	{
		if (a <= l && r <= b)
		{
			return {li[k], mi[k], ri[k]};
		}
		else if (a < r && l < b)
		{
			VP p1 = query(a, b, 2*k + 1, l, (r + l)/2), p2 = query(a, b, 2*k + 2, (r + l)/2, r);

			VP ans(3);

			ans[0] = p1[0].first == MAXINT ? p2[0] : p1[0];
			ans[2] = p2[2].first == MAXINT ? p1[2] : p2[2];

			ans[1] = maxP(p1[1], p2[1]);

			if (p1[2].first == p2[0].first && p1[2].first != MAXINT)
			{
				ans[1] = maxP(ans[1], P(p1[2].first, p1[2].second + p2[0].second));
			}

			if (ans[0].first == ans[1].first) ans[0].second = ans[1].second;
			if (ans[0].first == ans[2].first) ans[2].second = ans[1].second;

			return ans;
		}
		else
		{
			return {P(MAXINT, 0), P(MAXINT, 0), P(MAXINT, 0)};
		}
	}

	void print()
	{
		print(li); print(mi); print(ri);
	}

	void print(VP vp)
	{
		int a = 0, b = 2;
		for (int i = 0; i != vp.size(); ++i)
		{
			cout << vp[i].first << ' ' << vp[i].second << " | ";

			if (i == a)
			{
				cout << endl;

				a += b;

				b *= 2;
			}
		}
	}

private:
	P maxP(const P& p1, const P& p2)
	{
		return p1.second > p2.second ? p1 : p2;
	}

	int n;
	VP li, mi, ri;

};


class FV
{
public:
	void solve(VI a, VP range)
	{
		int n = a.size();

		ST st(n);

		for (int i = 0; i != n; ++i)
		{
			st.update(i, a[i]);
		}
		
		st.print();

		for (auto& p : range)
		{
			auto ans = st.query(p.first - 1, p.second, 0, 0, n);

			cout << ans[1].first << ' ' << ans[1].second << endl;
		}
	}

};


int main(int argc, char** argv)
{
	FV a;

	a.solve({-1, -1, 1, 1, 1, 1, 3, 10, 10, 10}, {P(2, 3), P(1, 10), P(5, 10)});

	return 0;
}
