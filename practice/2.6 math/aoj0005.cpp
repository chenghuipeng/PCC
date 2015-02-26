/** @file
  * @brief AOJ0005 GCD and LCM
  * @author malin
  * @date 2014年07月14日 星期一 15时42分34秒
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


class GaL
{
public:
	P solve(int a, int b)
	{
		int g = gcd(a, b);

		return P(g, a*(b/g));
	}

private:
	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a%b);
	}

};


int main(int argc, char** argv)
{
	GaL a;

	auto p =  a.solve(50000000, 30000000);

	cout << p.first << ' ' << p.second << endl;

	return 0;
}
