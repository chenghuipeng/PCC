/** @file
  * @brief POJ1222 Extend light on
  * @author malin
  * @date 2014年08月01日 星期五 10时40分11秒
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


class ELO
{
public:
	vector<VI> solve(vector<VI> A)
	{
		a = A;

		int r = a.size(), c = a[0].size();
		vector<VI> opt(r, VI(c, 0)), f(r, VI(c, 0));

		int res = r*c + 1;

		for (int i = 0; i != 1 << c; ++i)
		{
			int cnt = 0;

			for (int j = 0; j != c; ++j)
			{
				cnt += (f[0][j] = (i >> j) & 1);
			}

			for (int j = 1; j != r; ++j)
			{
				for (int k = 0; k != c; ++k)
				{
					cnt += (f[j][k] = get(j - 1, k, f));
				}
			}

			bool flag = true;
			for (int j = 0; j != c; ++j)
			{
				if (get(r - 1, j, f))
				{
					flag = false;
					break;
				}
			}

			if (flag && cnt < res)
			{
				opt = f;
				res = cnt;
			}
		}

		return opt;
	}

private:
	int get(int i, int j, vector<VI>& f)
	{
		int cnt = a[i][j], m = f.size(), n = f[0].size();

		for (int k = 0; k != 4; ++k)
		{
			int di = i + dx[k], dj = j + dy[k];

			if (0 <= di && di < m && 0 <= dj && dj < n) cnt += f[di][dj];
		}

		return cnt & 1;
	}

	vector<VI> a;
	int dx[4] = {-1, 0, 0, 0}, dy[4] = {0, -1, 0, 1};

};


int main(int argc, char** argv)
{
	ELO a;

	for (auto& v : a.solve({{0, 1, 1, 0, 1, 0}, {1, 0, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 1}, {0, 1, 1, 1, 0, 0}}))
	{
		for (auto x : v) cout << x << ' ';

		cout << endl;
	}

	return 0;
}
