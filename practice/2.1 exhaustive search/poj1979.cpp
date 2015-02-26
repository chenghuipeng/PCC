/** @file 
  * @brief POJ1979 Red and Black
  * @author malin
  * @date 23/06/14 14:10
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

class RAB
{
public:
	int tileCount(vector<string> room, int w, int h)
	{
		W = w; H = h; Room = room;
		
		unsigned i = 0, j = 0;
		FOR1(i, 0, H)
		{
			FOR1(j, 0, W)
			{
				if (room[i][j] == '@')
				{
					dfs(i, j);
				}
			}
		}
		
		return ans;
	}
	
private:
	void dfs(unsigned i, unsigned j)
	{
		unsigned k = 0;
		FOR1(k, 0, 4)
		{
			unsigned ii = i + x[k], jj = j +y[k];
			if (ii >= 0 && ii < H && jj < W && jj >=0)
			{
				if (Room[ii][jj] == '.')
				{
					++ ans;
					Room[ii][jj] = '#';
					dfs(ii, jj);
				}
			}
		}
	}
	
	int W, H;
	vector<string> Room;
	int x[4] = {-1, 0, 1, 0};
	int y[4] = {0, -1, 0, 1};
	int ans = 1;
	
};

int main(int argc, char* argv[])
{
	RAB a;
	
	cout << a.tileCount({".#.........", ".#.#######.", ".#.#.....#.", ".#.#.###.#.", ".#.#..@#.#.", ".#.#####.#.",
		".#.......#.", ".#########.", "..........."}, 11, 9) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

