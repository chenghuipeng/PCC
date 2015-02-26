/** @file
  * @brief segment tree for RMQ
  * @author malin
  * @date 2014年08月02日 星期六 15时54分57秒
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
		init(n_);
	}

	void init(int n_)
	{
		while (n < n_) n *= 2;

		array.assign(2*n - 1, MAXINT);
	}

	void update(int k, int v)
	{
		array[k += n - 1] = v;

		while (k > 0)
		{
			k = (k - 1)/2;
			array[k] = min(array[k*2 + 1], array[k*2 + 2]);
		}
	}

	int query(int a, int b, int k, int l, int r)
	{
		if (b <= l || r <= a) return MAXINT;

		if (a <= l && r <= b) return array[k];

		return min(query(a, b, 2*k + 1, l, (r + l)/2), query(a, b, 2*k + 2, (r + l)/2, r));
	}

private:
	VI array;
	int n = 1;

};


int main(int argc, char** argv)
{
	int n = 8;

	ST a(n);

	for (int i = 0; i != n; ++i)
	{
		a.update(i, n - i);
	}

	cout << a.query(3, 7, 0, 0, n) << endl;

	return 0;
}
