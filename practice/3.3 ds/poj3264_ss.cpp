/** @file
  * @brief POJ3264 Balanced LineUp
  * @author malin
  * @date 2014年08月06日 星期三 15时47分49秒
  * @version 1.0
  * @note
  * In this version, we use the Square Segmention. The complicity is Q*sqrt(N).
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


class BL
{
public:
	void solve(i
			while (l % b != 0 && l <= r)
			{
				maxh = max(maxh, h[l]);
				minh = min(minh, h[l]);
				
				++ l;
			}
			
			if (l == r && l % b == 0)
			{
				maxh = max(maxh, h[l]);
				minh = min(minh, h[l]);
			}

			while (l < r)
			{
				minh = min(minh, buckets[l/b][0]);
				maxh = max(maxh, buckets[l/b].back());

				l += b;
			}

			cout << maxh - minh << endl;
		}
	}

};


int main(int argc, char** argv)
{
	BL a;

	a.solve({1, 7, 3, 4, 2, 5}, {P(1, 5), P(4, 6), P(2, 2)});

	return 0;
}
