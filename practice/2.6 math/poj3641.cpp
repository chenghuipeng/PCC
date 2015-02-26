/** @file
  * @brief POJ3641 Pseudoprime numbers
  * @author malin
  * @date 2014年07月15日 星期二 14时18分39秒
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
	string is_pprime(int p, int a)
	{
		return !is_prime(p) && mod_pow(p, a, p) == a%p ? "yes" : "no";
	}

private:
	bool is_prime(int n)
	{
		for (int i = 2; i*i <= n; ++i)
		{
			if (n%i == 0) return false;
		}

		return true;
	}

	int mod_pow(int n, int a, int mod)
	{
		int res = 1;


		while (n > 0)
		{
			if (n & 1) res = res*a%mod;

			a = a*a%mod;

			n >>= 1;
		}

		return res;
	}

};


int main(int argc, char** argv)
{
	PN a;

	cout << a.is_pprime(1105, 3) << endl;
	
	return 0;
}
