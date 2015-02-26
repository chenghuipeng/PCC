/** @file
  * @brief gcd extgcd
  * @author malin
  * @date 2014年07月14日 星期一 09时30分29秒
  * @version 1.0
  * @note
  * The mathmatical methods in PCC 2.6
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


class Math
{
public:
	static int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a%b);
	}

	static int extgcd(int a, int b, int& x, int& y)
	{
		int d = a;

		if (b != 0)
		{
			d = extgcd(b, a%b, y, x);
			y -= (a/b)*x;
		}
		else
		{
			x = 1; y = 0;
		}

		return d;
	}

};


int main(int argc, char** argv)
{
	int a = 15, b = 9;

	cout << Math::gcd(a, b) << endl;

	int x, y;

	cout << Math::extgcd(a, b, x, y) << endl;

	cout << x << ' ' << y << endl;

	return 0;
}
