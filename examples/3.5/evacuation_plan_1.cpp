/**
  * @file Evacuation Plan
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


void solve(int n, int m, VI X, VI Y, VI B, VI P, VI Q, VI C, vector<VI> E)
{
	int s = n + m, t = s + 1;
	
	int i = 0, j = 0;
	
	int cost = 0, F = 0;
	
	FOR1(i, 0, n)
	{
		FOR1(j, 0, m)
		{
			int d = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
			
			add_edge(i, n + j, INF, d);
			
			cost += E[i][j] * d;
		}
	}
	
	FOR1(i, 0, n)
	{
		F += B[i];
		
		add_edge(s, i, B[i], 0);
	}
	
	FOR1(i, 0, m)
	{
		add_edge(n + i, t, C[i], 0);
	}
	
	if (min_cost_flow(s, t, F, t + 1) < cost)
	{
		cout << "SUBOPTIMAL" << endl;
		
		FOR1(i, 0, n)
		{
			FOR1(j, 0, m)
			{
				cout << G[n + j][i].cap << ' ';
			}
			cout << endl;
		}
	}
	else
	{
		cout << "OPTIMAL" << endl;
	}
}


int main(int argc, char** argv)
{
	solve(3, 4, {-3, -2, 2}, {3, -2, 2}, {5, 6, 5}, {-1, 1, -2, 0}, {1, 1, -2, -1}, {3, 4, 7, 3},
			{{3, 1, 1, 0}, {0, 0, 6, 0}, {0, 3, 0, 2}});
			
	return 0;
}

/*

for convenient

*/

