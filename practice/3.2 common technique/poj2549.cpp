/** @file
  * @brief POJ2549 Sumsets
  * @author malin
  * @date 2014年08月01日 星期五 16时18分44秒
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


class T
{
public:
	T(int a, int b, int c) : s(a), x(b), y(c) {}

	int s, x, y;
};

bool operator < (const T& lhs, const T& rhs)
{
	return lhs.s < rhs.s;
}

bool operator == (const T& lhs, const T& rhs)
{
	return lhs.s == rhs.s;
}

bool operator > (const T& lhs, const T& rhs)
{
	return lhs.s > rhs.s;
}


class Sumset
{
public:
	int solve(VI a)
	{
		sort(a.begin(), a.end());

		int i = 0, j = 0, n = a.size();

		vector<T> sets;

		FOR1(i, 0, n)
		{
			FOR1(j, 0, n)
			{
				if (j != i)
				{
					sets.push_back(T(a[i] + a[j], i, j));
				}
			}
		}

		sort(sets.begin(), sets.end());

		FOR2(i, n - 1, 0)
		{
			FOR1(j, 0, n)
			{
				if (i == j) continue;

				int s = a[i] - a[j];

				auto itr = lower_bound(sets.begin(), sets.end(), T(s, 0, 0));

				if (itr != sets.end() && itr->s == s && judge(i, j, itr->x, itr->y))
				{
					return a[i];
				}
			}
		}

		return MAXINT;
	}

private:
	bool judge(int i, int j, int m, int n)
	{
		return i != m && i != n && j != m && j != n;
	}

};


int main(int argc, char** argv)
{
	Sumset a;

	int ans = a.solve({2, 16, 64, 256, 1024});

	if (ans == MAXINT)
	{
		cout << "No Solution" << endl;
	}
	else
	{
		cout << ans << endl;
	}

	return 0;
}
