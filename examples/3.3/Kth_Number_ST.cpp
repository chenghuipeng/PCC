/** @file
  * @brief K-th Number
  * @author malin
  * @date 2014年08月04日 星期一 15时48分41秒
  * @version 1.0
  * @note
  * In this version, we use the segment tree.
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
	ST(VI l)
	{
		L = l;

		int n_ = l.size();

		while (n < n_) n *= 2;

		array.assign(2*n - 1, VI());

		init(0, 0, n_);

		L.clear(); L.shrink_to_fit();
	}

	void init(int k, int l, int r)
	{
		if (r - l == 1)
		{
			array[k].push_back(L[l]);
		}
		else
		{
			int lch = 2 * k + 1, rch = 2 * k + 2;

			init(lch, l, (r + l)/2);
			init(rch, (l + r)/2, r);

			array[k].resize(r - l);

			merge(array[lch].begin(), array[lch].end(), array[rch].begin(), array[rch].end(), array[k].begin());
		}
	}

	int query(int a, int b, int x, int k, int l, int r)
	{
		if (a <= l && r <= b)
		{
			return upper_bound(array[k].begin(), array[k].end(), x) - array[k].begin();
		}
		else if (a < r && l < b)
		{
			return query(a, b, x, 2*k + 1, l, (r + l)/2) + query(a, b, x, 2*k + 2, (r + l)/2, r);
		}
		else
		{
			return 0;
		}
	}


private:
	int n = 1;
	VI L;
	vector<VI> array;

};


class KN
{
public:
	void solve(VI A, VI I, VI J, VI K)
	{
		ST st(A);

		VI nums = A;

		int n = A.size();

		sort(nums.begin(), nums.end());

		for (int i = 0; i != I.size(); ++i)
		{
			int l = I[i] - 1, r = J[i], k = K[i];

			int lb = -1, ub = n;

			while (ub - lb > 1)
			{
				int mid = (ub + lb)/2, x = nums[mid];

				if (st.query(l, r, x, 0, 0, n) >= k)
				{
					ub = mid;
				}
				else
				{
					lb = mid;
				}
			}

			cout << nums[ub] << endl;
		}
	}

};


int main(int argc, char** argv)
{
	KN a;

	a.solve({1, 5, 2, 6, 3, 7, 4}, {2, 4, 1}, {5, 4, 7}, {3, 1, 3});

	return 0;
}
