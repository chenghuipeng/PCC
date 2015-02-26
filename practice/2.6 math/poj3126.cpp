/** @file
  * @brief POJ3126 Prime Path
  * @author malin
  * @date 2014年07月15日 星期二 09时37分34秒
  * @version 1.0
  * @note
  * Need a purning operation - if a prime has been visited, we needn't consider it any more.
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <set>
#include <queue>

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


class PP
{
public:
	int minCost(int a, int b)
	{
		VI prime; prime.reserve(10000);

		segment_sieve(prime, 1000, 10000);

		cout << prime.size() << endl;

		queue<P> que; que.push(P(a, 0));

		vector<bool> used(10000, false);
		while (!que.empty())
		{
			P p = que.front(); que.pop();

			int cn = p.first;

			if (cn == b) return p.second;

			for (auto x : prime)
			{
				int s = 0;
				for (int i = 0; i != 4; ++i)
				{
					int e = cn/pow(10, i), f = x/pow(10, i);
					if (e%10 != f%10)
					{
						++ s;
					}
				}

				if (s == 1 && used[x] == false)
				{
					que.push(P(x, p.second + 1));
					used[x] = true;
				}
			}
		}

		return -1;
	}

private:
	void segment_sieve(VI& prime, int a, int b)
	{
		vector<bool> is_prime(b - a, true), is_prime_small(sqrt(b) + 2, true);
		is_prime_small[0] = is_prime_small[1] = false;

		for (int i = 2; i*i < b; ++i)
		{
			if (is_prime_small[i])
			{
				// Sieve [2, sqrt(b))
				for (int j = 2*i; j*j < b; j += i)
				{
					is_prime_small[j] = false;
				}
				// Sieve [a, b)
				for (int j = max(2, (a + i - 1)/i)*i; j < b; j += i)
				{
					is_prime[j - a] = false;
				}
			}
		}

		for (int i = 0; i != is_prime.size(); ++i)
		{
			if (is_prime[i]) prime.push_back(i + a);
		}
	}

};


int main(int argc, char** argv)
{
	PP a;

	cout << a.minCost(1373, 8017) << endl;

	return 0;
}
