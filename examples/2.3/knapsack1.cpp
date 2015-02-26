/** @file
  * @brief 0-1 Packets
  * @author malin
  * @date
  * @version 1.0
  * @note
  * Using the memory search 
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();

const double MAXREAL = numeric_limits<double>::max();
const double MINREAL = numeric_limits<double>::min();

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<pair<int, int> > VP;

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class Knapsack
{
public:
	int maxValue(VI ww, VI vv, int W)
	{
		w = ww; v = vv;
		
		memset(dp, -1, sizeof(dp));
		
		return rec(0, W);
	}
	
private:
	int rec(int i, int j)
	{
		if (dp[i][j] >= 0)
		{
			return dp[i][j];
		}
		
		int res;
		
		if (i == w.size())
		{
			res = 0;
		}
		else if (j < w[i])
		{
			res = rec(i+1, j);
		}
		else
		{
			res = max(rec(i+1, j), rec(i+1, j-w[i]) + v[i]);
		}
		
		return dp[i][j] = res;
	}
	
	int dp[100][100];
	VI w;
	VI v;
	
};

int main(int argc, char* argv[])
{
	Knapsack a;
	
	cout << a.maxValue({2, 1, 3, 2}, {3, 2, 4, 2}, 5) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

