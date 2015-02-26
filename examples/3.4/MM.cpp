/** @file
  * @brief Minimizing Maximizer
  * @author malin
  * @date 2014年08月08日 星期五 17时03分52秒
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


class ST
{
public:
	ST(int n_)
	{
		while (n < n_) n *= 2;

		data.assign(2*n - 1, MAXINT/2);
	}

	void set(int k, int x)
	{
		k += n - 1;

		data[k] = x;

		while (k > 0)
		{
			k = (k - 1)/2;

			data[k] = min(data[2*k + 1], data[2*k + 2]);
		}
	}

	int get(int a, int b, int k, int l, int r)
	{
		if ( r <= a || b <= l)
		{
			return MAXINT/2;
		}
		else if (a <= l && r <= b)
		{
			return data[k];
		}
		else
		{
			int lch = get(a, b, 2*k + 1, l, (l + r)/2), rch = get(a, b, 2*k + 2, (l + r)/2, r);

			return min(lch, rch);
		}
	}

	void print(int k)
	{
		if (k == -1)
		{
			for (int i = n - 1; i != 2*n - 1; ++i) cout << data[i] << ' ';
		}
		else
		{
			cout << data[k];
		}

		cout << endl;
	}

private:
	int n = 1;
	VI data;

};


class MM
{
public:
	int solve(int n_, VI s, VI t)
	{
		int n = 1;
		
		while (n < n_) n *= 2;
		
		VI dp(n + 1, MAXINT/2);

		ST st(n);
		
		dp[1] = 0;
		st.set(0, 0);

		for (int i = 0; i != t.size(); ++i)
		{
			int v = st.get(s[i] - 1, t[i], 0, 0, n) + 1;

			if (v < dp[t[i]])
			{
				dp[t[i]] = v;

				st.set(t[i] - 1, v);
			}
		}

		return dp[n_];
	}

};


int main(int argc, char** argv)
{
	MM a;

	cout << a.solve(40, {20, 1, 10, 20, 15, 30}, {30, 10, 20, 30, 25, 40}) << endl;

	return 0;
}
