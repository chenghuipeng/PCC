/** @file
  * @brief POJ2566 Bound Found
  * @author malin
  * @date 2014年07月31日 星期四 09时31分46秒
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


class BF
{
public:
	vector<VI> solve(VI a, VI k)
	{
		vector<VI> ans(k.size(), VI(3, 0));
		VP psum(a.size() + 1, P(0, 0));

		for (int i = 0; i != a.size(); ++i)
		{
			psum[i + 1].first = psum[i].first + a[i];
			psum[i + 1].second = i + 1;
		}

		sort(psum.begin(), psum.end());

		for (int i = 0; i != k.size(); ++i)
		{
			int t = k[i], s = 0, e = 1, sum = 0, d = MAXINT;

			while (true)
			{
				while (e < psum.size() && (sum < t || s == e))
				{
					sum = psum[e++].first - psum[s].first;
					
					if (d > abs(sum - t))
					{
						d = abs(sum - t);

						int lb = psum[s].second, ub = psum[e - 1].second;
						if (lb > ub) swap(lb, ub);
						ans[i][0] = sum; ans[i][1] = lb + 1; ans[i][2] = ub;
					}
				}

				if (sum < t)
				{
					break;
				}

				while (s < e && sum >= t)
				{
					sum = psum[e - 1].first - psum[++s].first;

					if (d > abs(sum - t))
					{
						d = abs(sum - t);

						int lb = psum[s].second, ub = psum[e - 1].second;
						if (lb > ub) swap(lb, ub);
						ans[i][0] = sum; ans[i][1] = lb + 1; ans[i][2] = ub;
					}
				}
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	BF a;

	auto ans = a.solve({-9, 8, -7, 6, -5, 4, -3, 2, -1, 0}, {5, 11});

	for (auto& v : ans)
	{
		for (auto x : v)
		{
			cout << x << ' ';
		}
		cout << endl;
	}

	return 0;
}
