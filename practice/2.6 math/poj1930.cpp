/** @file
  * @brief POJ1930 Dead Fraction
  * @author malin
  * @date 2014年07月14日 星期一 17时11分39秒
  * @version 1.0
  * @note
  * The repeat portions value is x/9, x is the repeat number.
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


class DF
{
public:
	P solve(string a)
	{
		int i = 0, j = a.size() - 4;
		while (a[j] == a[j - 1])
		{
			-- j;
		}
		
		int nm = 0;

		FOR1(i, 2, j)
		{
			nm += (a[i] - '0')*pow(10, j - i - 1);
		}

		nm = nm*9 + a[j] - '0';

		int dm = 9*pow(10, j - 2);

		int d = gcd(nm, dm);

		return P(nm/d, dm/d);
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
	DF a;

	auto p = a.solve("0.0...");

	cout << p.first << ' ' << p.second << endl;

	return 0;
}
