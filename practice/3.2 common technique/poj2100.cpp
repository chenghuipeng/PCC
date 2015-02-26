/** @file
  * @brief POJ2100 Graveyard Design
  * @author malin
  * @date 2014年07月31日 星期四 16时54分53秒
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

class GD
{
public:
	vector<VI> solve(ll N)
	{
		ll n = ceil(sqrt(N));

		ll sum = 0, s = 1, t = 1;

		vector<VI> ans;

		while (true)
		{
			while (t < n && sum < N)
			{
				sum += pow(t++, 2);
			}

			if (sum < N) break;

			if (sum == N)
			{
				VI tmp; tmp.push_back(t - s);

				for (int i = s; i != t; ++i)
				{
					tmp.push_back(i);
				}

				ans.push_back(move(tmp));
			}

			if (s < t)
			{
				sum -= pow(s++, 2);
			}
		}

		return move(ans);
	}

};


int main(int argc, char** argv)
{
	GD a;

	for (auto& v : a.solve(2030))
	{
		for (auto x : v) cout << x << ' ';

		cout << endl;
	}

	return 0;
}
