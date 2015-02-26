/** @file
  * @brief Exponentiation
  * @author malin
  * @date 2014年07月14日 星期一 15时12分01秒
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


class Exponentiation
{
public:
	bool is_CN(int n)
	{
		for (int i = 1; i != n; ++i)
		{
			if (mod_pow(i, n, n) != i)
			{
				return false;
			}
		}

		return true;
	}

private:
	int mod_pow(int x, int n, int mod)
	{
		int ans = 0;

		while (n > 0)
		{
			if (n & 1) ans = ans * x %mod;

			x = x * x % mod;
			n >>= 1;
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	Exponentiation a;

	cout << boolalpha << a.is_CN(17) << endl;
	return 0;
}
