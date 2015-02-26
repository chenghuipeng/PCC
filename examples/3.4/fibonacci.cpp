/** @file
  * @brief get the n-th value in the fibonacci
  * @author malin
  * @date 2014年08月08日 星期五 15时48分53秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "matrix.h"

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


class F
{
public:
	int solve(int M, ll n)
	{
		mat A(2, VI(2));

		A[0][0] = A[0][1] = A[1][0] = 1; A[1][1] = 0;

		A = pow(A, n, M);

		return A[1][0];
	}

};


int main(int argc, char** argv)
{
	F a;

	cout << a.solve(10000, 10) << endl;

	return 0;
}
