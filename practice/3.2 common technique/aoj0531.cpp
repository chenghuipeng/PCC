/** @file
  * @brief AOJ0531 Paint Color
  * @author malin
  * @date 2014年08月01日 星期五 16时59分15秒
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


class PC
{
public:
	int solve(int w, int h, VI X1, VI X2, VI Y1, VI Y2)
	{
		x1 = X1; x2 = X2; y1 = Y1; y2 = Y2;

		int W = compress(x1, x2, w), H = compress(y1, y2, h);

		vector<VI > G(H, VI(W, false));

		for (int i = 0; i != x1.size(); ++i)
		{
			-- G[y2[i]][x1[i]];
			++ G[y2[i]][x2[i]];
			-- G[y1[i]][x2[i]];
			++ G[y1[i]][x1[i]];
		}
		
		for (int i = 0; i != W; ++i)
		{
			for (int j = 1; j != H; ++j)
			{
				G[j][i] += G[j-1][i];
			}
		}
		
		for (int i = 0; i != H; ++i)
		{
			for (int j = 1; j != W; ++j)
			{
				G[i][j] += G[i][j-1];
			}
		}
		
		-- W; -- H;

		// bfs
		int ans = 0;

		int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

		for (int i = 0; i != H; ++i)
		{
			for (int j = 0; j != W; ++j)
			{	
				if (G[i][j] > 0) continue;

				++ ans;

				queue<P> que; que.push(P(i, j));

				while (!que.empty())
				{
					P p = que.front(); que.pop();

					int y = p.first, x = p.second;

					G[y][x] = 1;

					for (int k = 0; k != 4; ++k)
					{
						int xx = x + dx[k], yy = y + dy[k];

						if (0 <= xx && xx < W && 0 <= yy && yy < H && G[yy][xx] == 0) que.push(P(yy, xx));
					}
				}
			}
		}

		return ans;
	}

private:
	int compress(VI& s1, VI& s2, int l)
	{
		VI ss;
		for (int i = 0; i != s1.size(); ++i)
		{
			for (int d = -1; d <= 1; ++d)
			{
				int a = s1[i] + d, b = s2[i] + d;

				if (1 <= a && a <= l) ss.push_back(a);
				if (1 <= b && b <= l) ss.push_back(b);
			}
		}

		sort(ss.begin(), ss.end());
		ss.erase(unique(ss.begin(), ss.end()), ss.end());

		for (int i = 0; i != s1.size(); ++i)
		{
			s1[i] = lower_bound(ss.begin(), ss.end(), s1[i]) - ss.begin();
			s2[i] = lower_bound(ss.begin(), ss.end(), s2[i]) - ss.begin();
		}

		return ss.size();
	}

	VI x1, x2, y1, y2;

};


int main(int argc, char** argv)
{
	PC a;

	cout << a.solve(15, 6, {1, 2, 1, 6, 7, 7, 9, 11, 12, 11}, {5, 4, 5, 7, 9, 9, 10, 14, 13, 14},
					{4, 1, 0, 1, 5, 0, 1, 0, 1, 5}, {6, 5, 1, 5, 6, 2, 5, 1, 5, 6}) << endl;

	return 0;
}
