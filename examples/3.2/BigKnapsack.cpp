/** @file
  * @brief Big Knapsack
  * @author malin
  * @date 2014年07月30日 星期三 16时29分54秒
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

class BK
{
public:
	ll maxValue(vector<ll> w, vector<ll> v, ll W)
	{
		int n = w.size(), ln = n/2, rn = n - ln;

		vector<pair<ll, ll> > ps;

		for (int i = 0; i != 1 << rn; ++i)
		{
			ll sw = 0, sv = 0;
			for (int j = 0; j != rn; ++j)
			{
				if (i & (1 << j))
				{
					sw += w[ln + j];
					sv += v[ln + j];
				}
			}

			ps.push_back(make_pair(sw, sv));
		}

		sort(ps.begin(), ps.end());

		vector<pair<ll, ll> > vw; vw.push_back(ps[0]);
		for (int i = 1; i != ps.size(); ++i)
		{
			if (ps[i].second >= vw.back().second)
			{
				vw.push_back(ps[i]);
			}
		}

		ll ans = 0;
		for (int i = 0; i != 1 << ln; ++i)
		{
			ll sw = 0, sv = 0;
			for (int j = 0; j != ln; ++j)
			{
				if (i & (1 << j))
				{
					sw += w[j];
					sv += v[j];
				}
			}

			sw = W - sw;

			int lb = -1, ub = vw.size();

			while (ub - lb > 1)
			{
				int mid = (ub + lb)/2;

				if (vw[mid].first > sw)
				{
					ub = mid;
				}
				else
				{
					lb = mid;
				}
			}

			if (0 <= lb) ans = max(ans, sv + vw[lb].second);
//			ans = max(ans, sv + (lower_bound(vw.begin(), vw.end(), make_pair(sw, (ll)MAXINT)) - 1)->second);
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	BK a;

	cout << a.maxValue({2, 1, 3, 2}, {3, 2, 4, 2}, 5) << endl;

	return 0;
}
