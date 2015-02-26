/** @file
  * @brief 4 Values Whose Sum is 0
  * @author malin
  * @date 2014年07月30日 星期三 16时07分15秒
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


class VWS
{
public:
	long long count(VI A, VI B, VI C, VI D)
	{
		int n = A.size();

		VI CD(n*n, 0);

		for (int i = 0; i != n; ++i)
		{
			for (int j = 0; j != n; ++j)
			{
				CD[i*n + j] = C[i] + D[j];
			}
		}

		sort(CD.begin(), CD.end());

		long long ans = 0;

		for (int i = 0; i != n; ++i)
		{
			for (int j = 0; j != n; ++j)
			{
				int x = 0 - (A[i] + B[j]);

				ans += upper_bound(CD.begin(), CD.end(), x) - lower_bound(CD.begin(), CD.end(), x);
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	VWS a;

	cout << a.count({-45, -41, -36, -36, 26, -32}, {22, -27, 53, 30, -38, -54},
					{42, 56, -37, -75, -10, -6}, {-16, 30, 77, -46, 62, 45}) << endl;

	return 0;
}
