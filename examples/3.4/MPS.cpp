/** @file
  * @brief Matrix Power Series
  * @author malin
  * @date 2014年08月08日 星期五 16时31分23秒
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


class MPS
{
public:
	mat solve(mat A, int k, int M)
	{
		int n = A.size();

		mat B(2*n, VI(2*n, 0));

		for (int i = 0; i != n; ++i)
		{
			for (int j = 0; j != n; ++j)
			{
				B[i][j] = A[i][j];
			}

			B[i + n][i] = B[i + n][i + n] = 1;
		}

		B = pow(B, k + 1, M);

		for (int i = 0; i != n; ++i)
		{
			for (int j = 0; j != n; ++j)
			{
				A[i][j] = B[i + n][j] % M;

				if (i == j) A[i][j] = (A[i][j] - 1 + M) % M; 
			}
		}

		return A;
	}

};


int main(int argc, char** argv)
{
	MPS a;

	auto ans =  a.solve({{0, 1}, {1, 1}}, 2, 4);

	for (auto& v : ans)
	{
		for (auto x : v) cout << x << ' '; cout << endl;
	}

	return 0;
}
