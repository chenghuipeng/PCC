/** @file
  * @brief Face the Right Way
  * @author malin
  * @date 2014年07月29日 星期二 19时56分30秒
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


class FRW
{
public:
	P solve(string A)
	{
		a = A;

		int K = 0, M = a.size();

		for (int k = 1; k <= a.size(); ++k)
		{
			int tmp = count(k);

			if (tmp != -1 && M > tmp)
			{
				M = tmp;
				K = k;
			}
		}

		return P(M, K);
	}

private:
	int count(int k)
	{
		VI f(a.size(), 0);

		int cnt = 0, ans = 0;

		for (int i = 0; i + k <= a.size(); ++i)
		{
			if ((cnt + (a[i] == 'B' ? 1 : 0)) & 1)
			{
				cnt += (f[i] = 1);
				++ ans;
			}

			if (i >= k - 1)
			{
				cnt -= f[i - k + 1];
			}
		}

		for (int i = a.size() - k + 1; i != a.size(); ++i)
		{
			if ((cnt + (a[i] == 'B' ? 1 : 0)) & 1)
			{
				return -1;
			}

			if (i >= k - 1)
			{
				cnt -= f[i - k + 1];
			}
		}

		return ans;
	}

	string a;

};


int main(int argc, char** argv)
{
	FRW a;

	auto p = a.solve("BBFBFBB");

	cout << p.first << ' ' << p.second << endl;

	return 0;
}
