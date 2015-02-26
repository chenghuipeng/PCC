/**
  * @file POJ3420 Quad Tiling 
  * @author malin
  * @date
  * @brief
  * @version
  */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "matrix.h"

using namespace std;

typedef pair<int, int> P;

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<P> VP;
typedef vector<bool> VB;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();
const int MAXREAL = numeric_limits<double>::max();
const int MINREAL = numeric_limits<double>::min();

#define FOR1(i, s, t) for (i = s; i != t; ++i)
#define FOR2(i, s, t) for (i = s; i >= t; --i)


class QT
{
public:
	int solve(int N, int M)
	{
		mat A(4, VI(4, 0));
		
		int a[] = {1, 5, 11, 36};
		
		if (N < 5)
		{
			return a[N - 1];
		}
		else
		{
			A[0][0] = 1; A[0][1] = 5; A[0][2] = 1; A[0][3] = -1;
			A[1][0] = A[2][1] = A[3][2] = 1;
			
			A = pow(A, N - 4, M);
			
			ll ans = (ll)36 * A[0][0] + 11 * A[0][1] + 5 * A[0][2] + A[0][3];
			
			return ans % M;
		}
	}
	
};


int main(int argc, char** argv)
{
	QT a;
	
	cout << a.solve(5, 10000) << endl;
	
	return 0;
}

/*

for convenient

*/

