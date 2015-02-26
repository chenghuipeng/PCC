/** @file 
  * @brief Lake Counting
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

using namespace std;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();

const double MAXREAL = numeric_limits<double>::max();
const double MINREAL = numeric_limits<double>::min();

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class LakeCounting
{
public:
	int count(vector<string> garden)
	{
		G = garden;
		
		int i, j, cnt = 0;
		FOR1(i, 0, G.size())
		{
			FOR1(j, 0, G[0].size())
			{
				if (G[i][j] == 'W')
				{
					dfs(j, i);
					++ cnt;
				}
			}
		}
		
		return cnt;
	}
	
private:
	void dfs(int x, int y)
	{
		G[y][x] = '.';
		
		int dx, dy;
		FOR1(dx, -1, 2)
		{
			FOR1(dy, -1, 2)
			{
				int nx = x + dx, ny = y + dy;
				if (0 <= nx && nx < G[0].size() && 0 <= ny && ny < G.size() && G[ny][nx] == 'W')
				{
					dfs(nx, ny);
				}
			}
		}
	}
		
	VS G;
	
};

int main(int argc, char* argv[])
{
	LakeCounting a;
	
	cout << a.count({"W........WW.", ".WWW.....WWW", "....WW...WW.", ".........WW.", ".........W..",
		"..W......W..", ".W.W.....WW.", "W.W.W.....W.", ".W.W......W.", "..W.......W."}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

