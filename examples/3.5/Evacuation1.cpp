/**
  * @file Evacuation with binary search 
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
#include <queue>
#include <memory.h>

#include "bipartite_graph_match.h"

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


const int MAX_X = 20;
const int MAX_Y = 20;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int X, Y;
char feild[MAX_X][MAX_Y + 1];

vector<int> dX, dY;
vector<int> pX, pY;

int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];


bool C(int t)
{
	int d = dX.size(), p = pX.size();
	
	V = d * t;
	
	for (int v = 0; v != V; ++v)
	{
		G[v].clear();
		
		for (int i = 0; i != d; ++i)
		{
			for (int j = 0; j != p; ++j)
			{
				if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0)
				{
					for (int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k <= t; ++k)
					{
						add_edge((k - 1) * d + i, d * t + j);
					}
				}
			}
		}
	}
	
	int cnt = bipartite_matching();
	
	return cnt == p;
}


void bfs(int x, int y, int d[MAX_X][MAX_Y])
{
	queue<P> que; que.push(P(x, y));
	
	d[x][y] = 0;
	
	while (!que.empty())
	{
		P p = que.front(); que.pop();
		
		for (int i = 0; i != 4; ++i)
		{
			int nx = p.first + dx[i], ny = p.second + dy[i];
			
			if (0 <= nx && nx < X && 0 <= ny && ny < Y && feild[nx][ny] == '.' && d[nx][ny] < 0)
			{
				d[nx][ny] = d[p.first][p.second] + 1;
				que.push(P(nx, ny));
			}
		}
	}
}


void solve(int XS, int YS, vector<vector<char> > f)
{
	X = XS; Y = YS;
	
	int i = 0, j = 0;
	
	FOR1(i, 0, X)
	{
		FOR1(j, 0, Y)
		{
			feild[i][j] = f[i][j];
		}
		
		feild[i][Y] = '\0';
	}
	
	int n = X * Y;
	
	dX.clear(); dY.clear(), pX.clear(), pY.clear();
	memset(dist, -1, sizeof(dist));
	
	FOR1(i, 0, X)
	{
		FOR1(j, 0, Y)
		{
			if (feild[i][j] == 'D')
			{
				dX.push_back(i);
				dY.push_back(j);
				
				bfs(i, j, dist[i][j]);
			}
			else if (feild[i][j] == '.')
			{
				pX.push_back(i);
				pY.push_back(j);
			}
		}
	}
	
	int lb = -1, ub = n + 1;
	
	while (ub - lb > 1)
	{
		int mid = (ub + lb)/2;
		
		if (C(mid))
		{
			ub = mid;
		}
		else
		{
			lb = mid;
		}
	}
	
	if (ub > n)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << ub << endl;
	}
}


int main(int argc, char** argv)
{
	solve(5, 5, {{'X', 'X', 'D', 'X', 'X'}, {'X', '.', '.', '.', 'X'}, {'D', '.', '.', '.', 'X'},
				{'X', '.', '.', '.', 'D'}, {'X', 'X', 'X', 'X', 'X'}}); 
	
	return 0;
}

/*

for convenient

*/

