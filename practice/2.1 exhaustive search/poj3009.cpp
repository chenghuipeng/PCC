/** @file 
  * @brief POJ3009 Curling 2.0
  * @author malin
  * @date 
  * @version 1.0
  * @note
  * The reason why this problem cannot use BFS is that when search the goal, the walls which are hited will be disappear.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <stack>

#include <fstream>

using namespace std;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();

const double MAXREAL = numeric_limits<double>::max();
const double MINREAL = numeric_limits<double>::min();

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define FOR1(i, s, n) for (i = s; i < n; ++i)

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

class Curling
{
public:
	int minimum(int w, int h, vector<vector<int> > board)
	{
		W = w; H = h; B = board;
		
		int i = 0, j = 0;
		FOR1(i, 0, H)
		{
			FOR1(j, 0, W)
			{
				if (B[i][j] == 2)
				{
					dfs(j, i, 0);
				}
			}
		}
		
		return Min <= 10 ? Min : -1;
	}
	
private:
	void dfs(int w, int h, int n)
	{
		if (n < 10)
		{
			int i = 0;
			FOR2(i, w-1, 0)
			{
				if (pro(i, h, n, 1, 0)) break;
			}
			FOR1(i, w+1, W)
			{
				if (pro(i, h, n, -1, 0)) break;
			}
			FOR2(i, h-1, 0)
			{
				if (pro(w, i, n, 0, 1)) break;
			}
			FOR1(i, h+1, H)
			{
				if (pro(w, i, n, 0, -1)) break;
			}
		}
	}
	
	bool pro(int w, int h, int n, int wi, int hi)
	{
		if (B[h][w] == 1)
		{
			B[h][w] = 0;
			dfs(w+wi, h+hi, n+1);
			B[h][w] = 1;
			return true;
		}
		if (B[h][w] == 3)
		{
			Min = min(Min, n+1);
			return true;
		}
		
		return false;
	}
	
	int W, H;
	vector<vector<int> > B;
	int Min = 11;
	
};

int main(int argc, char* argv[])
{
	Curling a;
	
	ifstream in("test.txt");
	
	int w, h;
	
	in >> w >> h;
	
	vector<vector<int> > b(h, vector<int>(w, 0));
	
	int n, cnt = 0;
	
	while(in >> n)
	{
		b[cnt/w][cnt%w] = n;
		++ cnt;
	}
	
	cout << a.minimum(w, h, b) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

