/** @file
  * @brief Fliptile
  * @author malin
  * @date 2014年07月30日 星期三 11时37分29秒
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


class Fliptile
{
public:
	vector<VI> solve(vector<VI> A)
	{
		a = A;

		int m = a.size(), n = a[0].size(), ans = m * n + 1;

		vector<VI> opt(m, VI(n, 0)), flip(m, VI(n, 0));

		for (int i = 0; i < 1 << n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j != n; ++j)
			{
				cnt += (flip[0][j] = ((i >> j) & 1));
			}

			for (int j = 1; j != m - 1; ++j)
			{
				for (int k = 0; k != n; ++k)
				{
					cnt += (flip[j][k] = color(j - 1, k, flip));
				}
			}

			bool f = true;
			for (int j = 0; j != n; ++j)
			{
				if (color(m - 1, j, flip))
				{
					f = false;
					break;
				}
			}

			if (f && cnt < ans)
			{
				ans = cnt;
				opt = flip;
			}
		}

		return (ans > m * n) ? vector<VI>() : opt;
	}

private:
	int color(int i, int j, vector<VI>& flip)
	{
		int c = a[i][j] + flip[i][j];

		for (int k = 0; k != 3; ++k)
		{
			int x = i + dx[k], y = j + dy[k];

			if (0 <= x && x < flip.size() && 0 <= y && y < flip[0].size()) c += flip[x][y];
		}

		return c & 1;
	}

	vector<VI> a;
	int dx[3] = {-1, 0, 0}, dy[3] = {0, -1, 1};

};


int main(int argc, char** argv)
{
	Fliptile a;

	auto ans = a.solve({{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}});

	if (ans.size() != 0)
	{
		for (auto& v : ans)
		{
			for (auto x : v)
			{
				cout << x << ' ';
			}
			cout << endl;
		}
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}
