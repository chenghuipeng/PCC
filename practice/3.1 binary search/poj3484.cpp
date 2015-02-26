/** @file
  * @brief POJ3484 Showstopper
  * @author malin
  * @date 2014年07月29日 星期二 11时19分15秒
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


class Showstopper
{
public:
	P solve(vector<VI> a)
	{
		int s = MAXINT, t = 0;

		for (auto& v : a)
		{
			s = min(s, v[0]);
			t = max(t, v[1]);
		}

		for (int i = 0; i <= t; ++i)
		{
			int cnt = 0;

			for (auto& v : a)
			{
				cnt += judge(v, i) ? 1 : 0;
			}

			if (cnt & 1)
			{
				return P(i, cnt);
			}
		}

		return P(0, 0);
	}

private:
	bool judge(VI v, int x)
	{
		int lb = 0, ub = (v[1] - v[0])/v[2] + 1;

		while (ub - lb > 1)
		{
			int mid = (ub + lb)/2;

			if (v[0] + v[2]*mid <= x)
			{
				lb = mid;
			}
			else
			{
				ub = mid;
			}
		}

		return v[0] + v[2]*lb == x;
	}

};


int main(int argc, char** argv)
{
	Showstopper a;

	P p = a.solve({{1, 10, 1}, {4, 4, 1}, {1, 5, 1}, {6, 10, 1}});

	if (p.first == 0 && p.second == 0)
	{
		cout << "no corruption" << endl;
	}
	else
	{
		cout << p.first << ' ' << p.second << endl;
	}

	return 0;
}
