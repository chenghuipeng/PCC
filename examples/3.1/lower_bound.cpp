/** @file
  * @brief lower_bound
  * @author malin
  * @date 2014年07月24日 星期四 10时22分13秒
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


class LB
{
public:
	int lower_bound(VI a, int k)
	{
		int lb = -1, ub = a.size();

		while (ub - lb > 1)
		{
			int mid = (ub + lb)/2;

			if (a[mid] >= k)
			{
				ub = mid;
			}
			else
			{
				lb = mid;
			}
		}

		return a[ub] <= k ? ub : a.size();
	}

};


int main(int argc, char** argv)
{
	LB a;

	cout << a.lower_bound(VI{2, 3, 3, 5, 6}, 3) << endl;


	return 0;
}
