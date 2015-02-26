/** @file
  * @brief POJ3185 The Water Bowls
  * @author malin
  * @date 2014年07月31日 星期四 17时14分25秒
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


class WB
{
public:
	int solve(VI A)
	{
		a = A; n = a.size(); f.assign(n, 0);

		int ans = n + 1;

		for (int k = 0; k <= 1; ++k)
		{
			int cnt = f[0] = k;

			for (int i = 1; i != n; ++i)
			{
				cnt += (f[i] = get(i - 1));
			}

			if (!get(n - 1)) ans = min(ans, cnt);
		}

		return ans;
	}

private:
	int get(int i)
	{
		int cnt = a[i];

		for (int d = -1; d != 1; ++d)
		{
			int di = i + d;
			if (0 <= di && di < n) cnt += f[di];
		}

		return cnt & 1;
	}

	VI a, f;
	int n;

};


int main(int argc, char** argv)
{
	WB a;

	cout << a.solve({0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}) << endl;
	return 0;
}
