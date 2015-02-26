/** @file
  * @brief POJ2429 GCD & LCM Inverse
  * @author malin
  * @date 2014年07月14日 星期一 16时16分58秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

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

class GLR
{
public:
	pair<ll, ll> solve(ll gcd, ll lcm)
	{
		ll n = lcm/gcd;

		vector<ll> ds;

		for (ll i = 2; i*i <= n; ++i)
		{
			ll d = 1;

			while (n%i == 0)
			{
				d *= i;
				n /= i;
			}

			ds.push_back(d);
		}

		if (n != 1) ds.push_back(n);

		n = lcm/gcd;

		queue<pair<ll, ll> > que; que.push(make_pair(0, 0));

		ll a = 0, sum = MAXINT;

		while (!que.empty())
		{
			pair<ll, ll> p = que.front(); que.pop();

			if (p.second == ds.size())
			{
				if (p.first != 0 && GCD(p.first, n/p.first) == 1 && p.first + n/p.first < sum)
				{
					a = p.first;
					sum = a + n/a;
				}
			}
			else
			{
				que.push(make_pair(p.first, p.second + 1));
				que.push(make_pair(p.first + ds[p.second - 1], p.second + 1));
			}
		}

		return make_pair(a*gcd, n/a*gcd);
	}

private:
	ll GCD(ll a, ll b)
	{
		if (b == 0) return a;

		return GCD(b, a%b);
	}

};


int main(int argc, char** argv)
{
	GLR a;

	auto p = a.solve(3, 60);

	cout << p.first << ' ' << p.second << endl;

	return 0;
}
