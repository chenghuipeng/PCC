/**
  * @file Farm Tour
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

#include "min_cost_flow_d.h"

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


void solve(int n, VI a, VI b, VI c)
{
	int s = 0, t = n - 1;
	
	for (int i = 0; i != a.size(); ++i)
	{
		add_edge(a[i] - 1, b[i] - 1, 1, c[i]);
		add_edge(b[i] - 1, a[i] - 1, 1, c[i]);
	}
	
	cout << min_cost_flow(s, t, 2, n) << endl;
}


int main(int argc, char** argv)
{
	solve(4, {1, 2, 3, 1, 2}, {2, 3, 4, 3, 4}, {1, 1, 1, 2, 2});
	
	return 0;
}

/*

for convenient

*/

