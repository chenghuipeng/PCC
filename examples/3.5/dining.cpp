/** 
  * @file Dining 
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


const int MAX_N = 100;
const int MAX_F = 100;
const int MAX_D = 100;


bool likeF[MAX_N][MAX_F];
bool likeD[MAX_N][MAX_D];


void solve(int n, int f, int d, vector<VI> lf, vector<VI> ld)
{
	int i = 0, j = 0;
	
	FOR1(i, 0, n)
	{
		for (auto x : lf[i])
		{
			likeF[i][x - 1] = true;
		}
		
		for (auto x : ld[i])
		{
			likeD[i][x - 1] = true;
		}
	}
	
	int s = 2 * n + f + d, t = s + 1;
	
	FOR1(i, 0, f)
	{
		add_edge(s, 2 * n + i, 1);
	}
	
	FOR1(i, 0, d)
	{
		add_edge(2 * n + f + i, t, 1);
	}
	
	FOR1(i, 0, n)
	{
		add_edge(i, n + i, 1);
	}
	
	FOR1(i, 0, n)
	{
		FOR1(j, 0, f)
		{
			if (likeF[i][j])
			{
				add_edge(2 * n + j, i, 1);
			}
		}
		
		FOR1(j, 0, d)
		{
			if (likeD[i][j])
			{
				add_edge(n + i, 2 * n + f + j, 1);
			}
		}
	}
	
	cout << max_flow(s, t) << endl;
}


int main(int argc, char** argv)
{
	solve(4, 3, 3, {{1, 2}, {2, 3}, {1, 3}, {1, 3}}, {{1, 3}, {1, 2}, {1, 2}, {3}});
	
	return 0;
}

/*

for convenient

*/

