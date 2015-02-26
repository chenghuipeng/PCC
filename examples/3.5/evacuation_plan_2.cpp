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


const int INF = std::numeric_limits<int>::max()/2;
const int MAX_V = 300;

int G[MAX_V][MAX_V];
int p[MAX_V][MAX_V];
bool used[MAX_V];


void solve(int n, int m, VI X, VI Y, VI B, VI P, VI Q, VI C, vector<VI> E)
{
	int V = n + m + 1;
	
	int i = 0, j  = 0, k = 0;
	
	FOR1(i, 0, V)
	{
		fill(G[i], G[i] + V, INF);
	}
	
	FOR1(j, 0, m)
	{
		int sum = 0;
		
		FOR1(i, 0, n)
		{
			int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
			
			G[i][n + j] = c;
			
			if (E[i][j] > 0) G[n + j][i] = -c;
			
			sum += E[i][j];
		}
		
		if (sum > 0) G[n + m][n + j] = 0;
		if (sum < C[j]) G[n + j][n + m] = 0;
	}
	
	FOR1(i, 0, V)
	{
		FOR1(j, 0, V)
		{
			p[i][j] = i;
		}
	}
	
	FOR1(k, 0, V)
	{
		FOR1(i, 0, V)
		{
			FOR1(j, 0, V)
			{
				if (G[i][j] > G[i][k] + G[k][j])
				{
					G[i][j] = G[i][k] + G[k][j];
					p[i][j] = p[k][j];
				}
				
				if (i == j && G[i][i] < 0)
				{
					fill(used, used + V, false);
					
					for (int v = i; !used[v]; v = p[i][v])
					{
						used[v] = true;
						if (v != n + m && p[i][v] != n + m)
						{
							if (v >= n)
							{
								++ E[p[i][v]][v - n];
							}
							else
							{
								-- E[v][p[i][v]];
							}
						}
					}
					
					cout << "SUBOPTIMAL" << endl;
					for (auto& v : E)
					{
						for (auto x : v)
						{
							cout << x << ' ';
						}
						cout << endl;
					}
					
					return;
				}
			}
		}
	}
	
	cout << "OPTIMAL" << endl;
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

