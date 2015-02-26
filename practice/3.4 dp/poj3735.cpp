/**
  * @file POJ3735 Training little cats 
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


class TC
{
public:
	void solve(int n, int m, vector<char> t, VI o1, VI o2)
	{
		int k = t.size();
		
		mat A(n + 1, VI(n + 1, 0));
		
		int i = 0, j = 0;
		
		FOR1(i, 0, n + 1)
		{
			A[i][i] = 1;
		}
		
		FOR1(i, 0, k)
		{
			int a = o1[i] - 1, b = o2[i] - 1;
			
			if (t[i] == 'g')
			{
				A[a][n] += 1;
			}
			else if (t[i] == 'e')
			{
				for (auto& x : A[a]) x = 0;
			}
			else
			{
				A[a][a] = A[b][b] = 0;
				A[a][b] = A[b][a] = 1;
				
				swap(A[a][n], A[b][n]);
			}
		}
		
		A = pow(A, m, MAXINT);
		
		mat B(n + 1, {0}); B[n][0] = 1;
		
		A = mul(A, B, MAXINT);
		
		FOR1(i, 0, n) cout << A[i][0] << ' '; cout << endl;
	}
	
};


int main(int argc, char** argv)
{
	TC a;
	
	a.solve(3, 1, {'g', 'g', 'g', 's', 'g', 'e'}, {1, 2, 2, 1, 3, 2}, {0, 0, 0, 2, 0, 0});
	
	return 0;
}

/*

for convenient

*/

