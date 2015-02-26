/** @file
  * @brief Crane
  * @author malin
  * @date 2014年08月03日 星期日 10时31分51秒
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


class ST
{
public:
	ST(VD l)
	{
		L = l; int n_ = L.size();

		int n = 1;

		while (n < n_)
		{
			n *= 2;
		}

		vx.assign(2*n - 1, 0);
		vy.assign(2*n - 1, 0);
		ang.assign(2*n - 1, 0);

		init(0, 0, n_);
	}

	void init(int k, int l, int r)
	{
		vx[k] = ang[k] = 0.0;

		if (r - l == 1)
		{
			vy[k] = L[l];
		}
		else
		{
			init(2*k + 1, l, (r + l)/2);
			init(2*k + 2, (r + l)/2, r);

			vy[k] = vy[2*k + 1] + vy[2*k + 2];
		}
	}

	void update(int s, double a, int v, int l, int r)
	{
		if (l <= s && s < r - 1)
		{		
			update(s, a, 2*v + 1, l, (r + l)/2);
			update(s, a, 2*v + 2, (r + l)/2, r);

			if (s < (r + l)/2)
			{
				ang[v] += a;
			}

			double si = sin(ang[v]), co = cos(ang[v]);

			vx[v] = vx[2*v + 1] + (co*vx[2*v + 2] - si*vy[2*v + 2]);
			vy[v] = vy[2*v + 1] + (si*vx[2*v + 2] + co*vy[2*v + 2]);
		}
	}

	pair<double, double> query(int k)
	{
		return make_pair(vx[k], vy[k]);
	}

private:
	VD L, vx, vy, ang;

};

class Crane
{
public:
	vector<pair<double, double> > solve(VD l, vector<P> C)
	{
		ST st(l);

		int n = l.size(); VD prv(n, M_PI);

		vector<pair<double, double> > ans;

		for (auto& p : C)
		{
			int s = p.first - 1; double a = p.second/360.0 * 2 * M_PI;

			st.update(s, a - prv[s], 0, 0, n);

			prv[s] = a;

			ans.push_back(st.query(0));
		}

		return move(ans);
	}

};


int main(int argc, char** argv)
{
	Crane a;

	auto ans = a.solve({10, 5}, {P(1, 90)});

	for (auto& p : ans)
	{
		cout << p.first << ' ' << p.second << endl;
	}

	return 0;
}
