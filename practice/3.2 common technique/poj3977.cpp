/** @file
  * @brief POJ3977 Subset
  * @author malin
  * @date 2014年08月01日 星期五 15时16分01秒
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


typedef long long ll;

class Subset
{
public:
	pair<ll, ll> solve(vector<ll> a)
	{
		int n1 = a.size()/2, n2 = a.size() - n1, n = n1 + n2, i = 0, j = 0;

		vector<pair<ll, int> > sets;

		FOR1(i, 1 << n1, 1 << n)
		{
			ll s = 0, cnt = 0;

			FOR1(j, n1, n)
			{
				if ((i >> j) & 1)
				{
					s += a[j];
					++ cnt;
				}
			}

			sets.push_back(make_pair(s, cnt));
		}

		sort(sets.begin(), sets.end());

		ll sum = numeric_limits<long long>::max(); int cnt = 0;

		FOR1(i, 0, 1 << n1)
		{
			ll s = 0, c = 0;

			FOR1(j, 0, n1)
			{
				if ((i >> j) & 1)
				{
					s += a[j];
					++ c;
				}
			}

			auto itr = lower_bound(sets.begin(), sets.end(), make_pair(-s, MAXINT));

			if (itr != sets.end())
			{
				update(sum, cnt, s + itr->first, c + itr->second);
			}
			update(sum, cnt, s + (itr - 1)->first, c + (itr - 1)->second);
		}

		return make_pair(sum, cnt);
	}

private:
	void update(ll& sum, int& cnt, ll s, int c)
	{
		if (sum > abs(s) && c != 0)
		{
			sum = abs(s);
			cnt = c;
		}
	}

};


int main(int argc, char** argv)
{
	Subset a;

	auto p = a.solve({20, 100, -100});

	cout << p.first << ' ' << p.second << endl;

	return 0;
}
