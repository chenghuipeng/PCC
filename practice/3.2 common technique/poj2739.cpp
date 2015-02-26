/** @file
  * @brief POJ2739 Sum of Consecutive Prime Numbers
  * @author malin
  * @date 2014年07月31日 星期四 16时26分49秒
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


class CPS
{
public:
	VI solve(VI a)
	{
		VI prime;

		int m = *max_element(a.begin(), a.end());

		vector<bool> is_prime(m + 1, true);

		for (int i = 2; i * i <= m; ++i)
		{
			if (is_prime[i])
			{
				for (int j = i * 2; j <= m; j += i)
				{
					is_prime[j] = false;
				}
			}
		}

		for (int i = 2; i != is_prime.size(); ++i)
		{
			if (is_prime[i]) prime.push_back(i);
		}

//		for (auto x : prime) cout << x << ' '; cout << endl;

		int n = a.size();

		VI ans(n, 0);

		for (int i = 0; i != n; ++i)
		{
			int sum = 0, s = 0, t = 0, cnt = 0;

			while (true)
			{
				while (t < prime.size() && sum < a[i])
				{
					sum += prime[t++];
				}

				if (sum < a[i]) break;

				if (sum == a[i]) ++ cnt;

				if (s < t) sum -= prime[s++];
			}

			ans[i] = cnt;
		}

		return move(ans);
	}

};


int main(int argc, char** argv)
{
	CPS a;

	for (auto x : a.solve({2, 3, 17, 41, 20, 666, 12, 53, 10007})) cout << x << ' '; cout << endl;

	return 0;
}
