/** @file
  * @brief subsequence
  * @author malin
  * @date 2014年07月29日 星期二 14时52分06秒
  * @version 1.0
  * @note
  * In this version, we use the binary search.
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


class Subsequence
{
public:
	int minLength(VI a, int S)
	{
		VI sum(a.size() + 1, 0);

		int i = 0;

		FOR1(i, 0, a.size())
		{
			sum[i + 1] = sum[i] + a[i];
		}

		if (sum[a.size()] < S)
		{
			return 0;
		}

		int n = sum.size(), ans = n;
		for (i = 0; sum[i] + S <= sum[n - 1]; ++i)
		{
			int lb = i, ub = n;

			while (ub - lb > 1)
			{
				int mid = (ub + lb)/2;

				if (sum[mid] - sum[i] >= S)
				{
					ub = mid;
				}
				else
				{
					lb = mid;
				}
			}

			ans = min(ans, ub - i);
//			ans = min(ans, lower_bound(sum.begin() + i, sum.end(), sum[i] + S) - sum.begin() - i);
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	Subsequence a;

	cout << a.minLength({5, 1, 3, 5, 10, 7, 4, 9, 2 ,8}, 15) << endl;
	
	return 0;
}
