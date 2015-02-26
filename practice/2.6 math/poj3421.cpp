/** @file
  * @brief POJ3421 X-factor Chains
  * @author malin
  * @date 2014年07月15日 星期二 10时51分31秒
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


class FC
{
public:
	P solve(int X)
	{
		VI ds;

		for (int i = 2; i*i <= X; ++i)
		{
			while (X%i == 0)
			{
				ds.push_back(i);
				X /= i;
			}
		}

		if (X != 1) ds.push_back(X);

		sort(ds.begin(), ds.end());

		int count = 1;

		while (next_permutation(ds.begin(), ds.end())) ++ count;

		return P(ds.size(), count);
	}

};


int main(int argc, char** argv)
{
	FC a;

	auto p = a.solve(4594590);

	cout << p.first << ' ' << p.second << endl;

	return 0;
}
