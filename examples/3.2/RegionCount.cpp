/** @file
  * @brief coordinate discretization
  * @author malin
  * @date 2014年07月30日 星期三 19时15分29秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <stack>

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


class RC
{
public:
	int count(int w, int h, VI x1, VI x2, VI y1, VI y2)
	{
		int H = compress(x1, x2, h), W = compress(y1, y2, w);

		vector<vector<bool> > a(W, vector<bool>(H, false));

		for (int i = 0; i != x1.size(); ++i)
		{
			for (int x = x1[i]; x <= x2[i]; ++x)
			{
				for (int y = y1[i]; y <= y2[i]; ++y)
				{
					a[y][x] = true;
				}
			}
		}

		int ans = 0;

		int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

		for (int y = 0; y != W; ++y)
		{
			for (int x = 0; x != H; ++x)
			{
				if (a[y][x]) continue;

				// dfs
				++ ans;

				stack<P> s; s.push(P(y, x));

				while (!s.empty())
				{
					P p = s.top(); s.pop();

					int yy = p.first, xx = p.second;

					a[yy][xx] = true;

					for (int i = 0; i != 4; ++i)
					{
						int tx = xx + dx[i], ty = yy + dy[i];

						if (0 <= tx && tx < H && 0 <= ty && ty < W && !a[ty][tx]) s.push(P(ty, tx));
					}
				}
			}
		}

		return ans;
	}

private:
	int compress(VI& x1, VI& x2, int w)
	{
		VI xs;

		for (int i = 0; i != x1.size(); ++i)
		{
			if (x1[i] == x2[i])
			{
				for (int d = -1; d <= 1; ++d)
				{
					int dx1 = x1[i] + d;

					if (1 <= dx1 && dx1 <= w) xs.push_back(dx1);
				}
			}
		}

		sort(xs.begin(),xs.end());

		xs.erase(unique(xs.begin(), xs.end()), xs.end());

		for (int i = 0; i != x1.size(); ++i)
		{
			x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
			
			auto itr = lower_bound(xs.begin(), xs.end(), x2[i]);
			if (itr == xs.end() || *itr != x2[i])
			{
				x2[i] = itr - xs.begin() - 1;
			}
			else
			{
				x2[i] = itr - xs.begin();
			}
		}

		return xs.size();
	}

};


int main(int argc, char** argv)
{
	RC a;

	cout << a.count(10, 10, {1, 1, 4, 9, 10}, {6, 10, 4, 9, 10}, {4, 8, 1, 1, 6}, {4, 8, 10, 5, 10}) << endl;
	return 0;
}
