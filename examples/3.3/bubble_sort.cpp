/** @file
  * @brief The frequency of data exchange in bubble sort
  * @author malin
  * @date 2014年08月03日 星期日 15时53分50秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "BIT.h"

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


typedef long long ll;

class BS
{
public:
	ll solve(VI a)
	{
		int n = a.size();

		BIT b(n);

		ll ans = 0;

		for (int i = 0; i != n; ++i)
		{
			ans += i - b.sum(a[i]);
			b.update(a[i], 1);
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	BS a;

	cout << a.solve({3, 1, 4, 2}) << endl;

	return 0;
}
