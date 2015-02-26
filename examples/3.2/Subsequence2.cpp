/** @file
  * @brief Subsequence
  * @author malin
  * @date 2014年07月29日 星期二 15时11分41秒
  * @version 1.0
  * @note
  * In this version, we use the rule extraction method.
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
		int sum = 0, s = 0, t = 0, n = a.size(), ans = n + 1;

		while (true)
		{
			while (t < n && sum < S)
			{
				sum += a[t++];
			}

			if (sum < S) break;

			ans = min(ans, t - s);

			sum -= a[s++];
		}

		return ans > n ? 0 : ans;
	}

};


int main(int argc, char** argv)
{
	Subsequence a;

	cout << a.minLength({5, 1, 3, 5, 10, 7, 4, 9, 2 ,8}, 15) << endl;

	return 0;
}
