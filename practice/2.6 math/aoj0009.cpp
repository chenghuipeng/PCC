/** @file
  * @brief POJ0009 Prime Number
  * @author malin
  * @date 2014年07月15日 星期二 09时14分55秒
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


class PN
{
public:
	int sieve(int n)
	{
		vector<bool> is_prime(n + 1, true);
		is_prime[0] = is_prime[1] = false;

		int ans = 0;

		for (int i = 2; i <= n; ++i)
		{
			if (is_prime[i])
			{
				for (int j = 2*i; j <= n; j += i)
				{
					is_prime[j] = false;
				}

				++ ans;
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	PN a;

	cout << a.sieve(11) << endl;

	return 0;
}
