/**
  * @file The Windy's 
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


void solve(int n, int m, vector<VI> Z)
{
	int s = n + n * m, t = s + 1;
	
	int i = 0, j = 0, k = 0;
	
	FOR1(i, 0, n)
	{
		add_edge(s, i, 1, 0);
	}
	
	FOR1(i, 0, n)
	{
		FOR1(j, 0, m)
		{
			add_edge(n + j * n + i, t, 1, 0);
			
			FOR1(k, 0, n)
			{
				add_edge(k, n + j * n + i, 1, (i + 1) * Z[k][j]);
			}
		}
	}
	
	cout << min_cost_flow(s, t, n, t + 1)/double(n) << endl;
}


int main(int argc, char** argv)
{
	solve(3, 4, {{1, 100, 100, 100}, {1, 99, 99, 99}, {98, 1, 98, 98}});
	return 0;
}

/*

for convenient

*/

