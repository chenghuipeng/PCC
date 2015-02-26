/** @file
  * @brief Physics Experiment
  * @author malin
  * @date 2014年07月30日 星期三 15时35分03秒
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


class PE
{
public:
	VD solve(int N, int H, int R, int T)
	{
		VD ans(N, 0);

		double t = sqrt(H/5.0);

		for (int i = 0; i != N; ++i)
		{
			int k = floor(T/t);

			ans[i] = H + 2*R*i/100.0 - (k & 1 ? 5*pow(k*t + t - T + i, 2) : 5*pow(T - i - k*t, 2));
		}

		sort(ans.begin(), ans.end());

		return move(ans);
	}

};


int main(int argc, char** argv)
{
	PE a;

	auto v = a.solve(2, 10 ,10 ,100);

	for (auto x : v)
	{
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
