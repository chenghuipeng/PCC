/**
  * @file Dual Core CPU 
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

#include "max_flow_d.h"

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


void solve(VI A, VI B, VI a, VI b, VI w)
{
	int n = A.size(), m = a.size(), s = n, t = s + 1, i = 0;
	
	FOR1(i, 0, n)
	{
		add_edge(s, i, B[i]);
		add_edge(i, t, A[i]);
	}
	
	FOR1(i, 0, m)
	{
		add_edge(a[i] - 1, b[i] - 1, w[i]);
		add_edge(b[i] - 1, a[i] - 1, w[i]);
	}
	
	cout << max_flow(s, t) << endl;
}


int main(int argc, char** argv)
{
	solve({1, 2, 10}, {10, 10, 3}, {2}, {3}, {1000});
	
	return 0;
}

/*

for convenient

*/

