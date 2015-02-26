/** @file
  * @brief POJ1995 Raising Modulo Numbers
  * @author malin
  * @date 2014年07月15日 星期二 15时02分57秒
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


class RMN
{
public:
	int solve(int mod, VP a)
	{
		int ans = 0;

		for (auto& p : a)
		{
			ans += mod_pow(p.first, p.second, mod);
		}
		
		return ans%mod;
	}

private:
	int mod_pow(int a, int n, int mod)
	{
		int res = 1;

		while (n > 0)
		{
			if (n & 1) res = res * a %mod;

			a = (long long)a * a % mod;

			n >>= 1;
		}

		return res;
	}

};


int main(int argc, char** argv)
{
	RMN a;

	cout << a.solve(36123, {{2374859, 3029382}}) << endl;
	return 0;
}
