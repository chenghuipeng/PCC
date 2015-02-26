/** @file 
  * @brief POJ3669 Meteor Shower
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
#include <memory.h>

#include <fstream>

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

char toLowerCase(char a) {return 'a' <= a && a <= 'z' ? a : a + 32;}

vector<string> split(string str, string pattern = " ")
{
	vector<string> result;

	string s("");
	for(int i = 0; i != str.size(); ++i)
	{
		if (pattern.find(str[i]) == string::npos)
		{
			s += str[i];
		}
		else
		{
			if (s != "")
			{
				result.push_back(s);
				s = "";
			}
		}
	}

	if (s != "") result.push_back(s);

	return result;
}

int str2int(string s)
{
	unsigned size = s.size();
	int out = 0;

	unsigned i = 0;
	FOR1(i, 0, size)
	{
		out += (s[i] - '0')*pow(10, size - i - 1);
	}

	return out;
}

class MeteorShower
{
public:
	int nearest(vector<vector<int> > meteors)
	{
		memset(m, -1, sizeof(m));
		memset(d, -1, sizeof(d));
		
		unsigned i = 0;
		FOR1(i, 0, meteors.size())
		{
			int x = meteors[i][0];
			int y = meteors[i][1];
			if (m[x][y] == -1 || m[x][y] > meteors[i][2])
			{
				m[x][y] = meteors[i][2];
			}
			for (auto k = 0; k !=4; ++k)
			{
				int xx = x + dx[k], yy = y + dy[k];
				if (0 <= xx && 0 <= yy)
				{
					if (m[xx][yy] == -1 || m[xx][yy] > meteors[i][2]) m[xx][yy] = meteors[i][2];
				}
			}
		}
		
		return bfs();
	}
	
private:
	int bfs()
	{
		queue<P> que;
		que.push(P(0, 0));
		d[0][0] = 0;
		
		while (!que.empty())
		{
			P p = que.front(); que.pop();
			
			int dd = d[p.first][p.second];
			
			if (m[p.first][p.second] == -1)
			{
				return dd;
			}
			
			unsigned k = 0;
			FOR1(k, 0, 4)
			{
				int nx = p.first + dx[k], ny = p.second + dy[k];
				if (0 <= nx && 0 <= ny && d[nx][ny] == -1 && (m[nx][ny] > dd + 1 || m[nx][ny] == -1))
				{
					que.push(P(nx, ny));
					d[nx][ny] = dd + 1;
				}
			}
		}
		
		return -1;
	}
	
	int m[300][300];
	int d[300][300];
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
};

int main(int argc, char* argv[])
{
	MeteorShower a;
	
	ifstream in("test.txt");
	
	int M; in >> M;
	vector<vector<int> > meteors(M, vector<int>(3, 0));
	
	int n, cnt = 0;
	while (in >> n)
	{
		meteors[cnt/3][cnt%3] = n;
		++cnt;
	}
	
	cout << a.nearest(meteors) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

