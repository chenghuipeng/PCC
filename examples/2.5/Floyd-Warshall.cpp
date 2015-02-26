/** @file
  * @brief Floyd-Warshall
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
typedef vector<pair<int, int> > VP;

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class FW
{
public:
	vector<VI> minDistances(vector<VI> G)
	{
		int V = G.size(), i, j, k;
		
		FOR1(k, 0, V)
		{
			FOR1(i, 0, V)
			{
				FOR1(j, 0, V)
				{
					G[i][j] = min(G[i][j], G[i][k] = G[k][j]);
				}
			}
		}
		
		return move(G);
	}
	
};

int main(int argc, char* argv[])
{
	return 0;
}

/**
  * just for convenient
  */

