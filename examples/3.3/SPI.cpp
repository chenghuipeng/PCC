/** @file
  * @brief A Simple Problem with Integers
  * @author malin
  * @date 2014年08月03日 星期日 16时33分28秒
  * @version 1.0
  * @note
  * In this version, we use the segment tree.
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


typedef long long ll;

class ST
{
public:
	ST(int n_)
	{
		int n = 1;

		while (n < n_) n *= 2;

		data.assign(2*n - 1, 0), datb.assign(2*n - 1, 0);
	}

	void update(int a, int b, int x, int k, int l, int r)
	{
		if (a <= l && r <= b)
		{
			data[k] += x;
		}
		else if (l < b && a < r)
		{
			datb[k] += (min(b, r) - max(a, l)) * x;
			update(a, b, x, 2*k + 1, l, (l + r)/2);
			update(a, b, x, 2*k + 2, (l + r)/2, r);
		}
	}

	ll query(int a, int b, int k, int l, int r)
	{
		if (b <= l || r <= a)
		{
			return 0;
		}
		else if (a <= l && r <= b)
		{
			return data[k] * (r - l) + datb[k];
		}
		else
		{
			ll res = data[k] * (min(b, r) - max(a, l));
			res += query(a, b, 2*k + 1, l, (l + r)/2);
			res += query(a, b, 2*k + 2, (l + r)/2, r);

			return res;
		}
	}

	void print()
	{
		for (auto x : data) cout << x << ' '; cout << endl;
		for (auto x : datb) cout << x << ' '; cout << endl;
	}

private:
	vector<ll> data, datb;

};


class SPI
{
public:
	void solve(VI A, vector<char> T, VI L, VI R, VI X)
	{
		int n = A.size();

		ST st(n);

		for (int i = 0; i != n; ++i)
		{
			st.update(i, i + 1, A[i], 0, 0, n);
		}

		for (int i = 0; i != T.size(); ++i)
		{
			if (T[i] == 'C')
			{
				st.update(L[i] - 1, R[i], X[i], 0, 0, n);
			}
			else
			{
				cout << st.query(L[i] - 1, R[i], 0, 0, n) << endl;
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
