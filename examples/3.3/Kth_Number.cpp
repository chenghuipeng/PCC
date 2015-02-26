/** @file
  * @brief K-th Number
  * @author malin
  * @date 2014年08月04日 星期一 14时46分02秒
  * @version 1.0
  * @note
  * In this version, we use the "Square Segmention".
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


class KN
{
public:
	void solve(VI A, VI I, VI J, VI K)
	{
		int n = A.size(), B = sqrt(n * log10(n)/log10(2));

		vector<VI> bucket(n/B + 1);

		VI nums = A;

		for (int i = 0; i != n; ++i)
		{
			bucket[i/B].push_back(A[i]);
		}

		sort(nums.begin(), nums.end());

		for (auto& v : bucket) sort(v.begin(), v.end());

		for (int i = 0; i != I.size(); ++i)
		{
			int l = I[i] - 1, r = J[i], k = K[i];

			int lb = -1, ub = n;

			while (ub - lb > 1)
			{
				int mid = (ub + lb)/2, x = nums[mid], cnt = 0, tl = l, tr = r;

				while (tl < tr && tl%B != 0) if (A[tl++] <= x) ++ cnt;
				while (tl < tr && tr%B != 0) if (A[--tr] <= x) ++ cnt;

				while (tl < tr)
				{
					auto& v = bucket[tl/B];

					cnt += upper_bound(v.begin(), v.end(), x) - v.begin();

					tl += B;
				}

				if (cnt >= k)
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
