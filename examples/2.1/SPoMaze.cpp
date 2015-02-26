/** @file 
  * @brief shortest path of maze
  * @author malin
  * @date 
  * @version 1.0
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();

const double MAXREAL = numeric_limits<double>::max();
const double MINREAL = numeric_limits<double>::min();

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class Maze
{
public:
	int ShortestPath(VS maze)
	{
		M = maze;
		
		for (int i = 0; i !=100; ++i)
		{
			for (int j = 0; j != 100; ++j)
			{
				d[i][j] = MAXINT;
			}
		}
		
		for (int i = 0; i != M.size(); ++i)
		{
			for (int j = 0; j != M[0].size(); ++j)
			{
				if (M[i][j] == 'S') return bfs(i, j);
			}
		}
	}
	
private:
	int bfs(int sx, int sy)
	{
		queue<P> que;
		que.push(P(sx, sy));
		d[sx][sy] = 0;
		
		while (!que.empty())
		{
			P p = que.front(); que.pop();
			int x = p.first, y = p.second;
			
			if (M[x][y] == 'G')
			{
				return d[x][y];
			}
			
			for (int i = 0; i != 4; ++i)
			{
				int nx = x + dx[i], ny = y + dy[i];
				
				if (0 <= nx && nx < M.size() && 0 <= ny && ny < M[0].size() && M[nx][ny] != '#' && d[nx][ny] == MAXINT)
				{
					que.push(P(nx, ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
	
	VS M;
	int d[100][100] = {};
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};

};

int main(int argc, char* argv[])
{
	Maze a;
	
	cout << a.ShortestPath({"#S######.#", "......#..#", ".#.##.##.#", ".#........", "##.##.####", 
		"....#....#", ".#######.#", "....#.....", ".####.###.", "....#...G#"}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

