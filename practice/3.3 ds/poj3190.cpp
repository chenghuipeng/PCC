/** @file
  * @brief POJ3190 Inner Vertices
  * @author malin
  * @date 2014年08月05日 星期二 10时42分37秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "../../examples/3.3/BIT.h"

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


class IV
{
public:
	int solve(VI X, VI Y)
	{
		int ans = X.size();

		int w = compress(X), h = compress(Y);

		b0.init(w); b1.init(w);

		vector<VI> segs(h);

		for (int i = 0; i != Y.size(); ++i)
		{
			segs[Y[i]].push_back(X[i]);
		}

		vector<bool> visited(X.size() + 1, false);

		for (auto& v : segs)
		{
			sort(v.begin(), v.end());

			b0.print(); b1.print();

			for (int i = 0; i != v.size(); ++i)
			{
				int x = v[i] + 1;

				int s = query(x, x + 1);

				if (visited[x])
				{
					ans += s;

					add(x, x + 1, -s);
				}
				else
				{
					visited[x] = true;
				}

				if (i + 1 != v.size())
				{
					add(x + 1, v[i + 1] + 1, 1);
				}
			}
			cout << endl;
		}

		return ans;
	}

private:
	int compress(VI& l)
	{
		VI ls = l;

		sort(ls.begin(), ls.end());

		ls.erase(unique(ls.begin(), ls.end()), ls.end());

		for (int i = 0; i != l.size(); ++i)
		{
			l[i] = lower_bound(ls.begin(), ls.end(), l[i]) - ls.begin();
		}

		return ls.size();
	}

	// add x in [l, r)
	void add(int l, int r, int x)
	{
		b0.update(l, -x * (l - 1));
		b1.update(l, x);
		b0.update(r, x * (r - 1));
		b1.update(r, -x);
	}

	// return the summary of [l, r)
	int query(int l, int r)
	{
		return b0.sum(r - 1) + b1.sum(r - 1) * (r - 1) - 
					(b0.sum(l - 1) + b1.sum(l - 1) * (l - 1));
	}

	BIT b0, b1;

};


int main(int argc, char** argv)
{
	IV a;

	cout << a.solve({0, 2, -2, 0}, {2, 0, 0, -2}) << endl;

	return 0;
}
