/** @file
  * @brief Dijkstra
  * @author malin
  * @date
  * @version 1.0
  * @note
  * Using the adjacency matrix method.
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


class Dijkstra
{
public:
	VI minDistance(vector<VI> G, int s)
	{
		VI d(G.size(), MAXINT/2);
		vector<bool> used(G.size(), false);
		
		d[s] = 0;
		
		int v = s;
		
		while (v != -1)
		{
			used[v] = true;
			
			int x = -1;
			for (int i = 0; i != d.size(); ++i)
			{
				d[i] = min(d[i], d[v] + G[v][i]);
				
				if (!used[i] && (x == -1 || d[i] < d[x])) x = i;
			}
			
			v = x;
		}
		
		return move(d);
	}
	
};

int main(int argc, char* argv[])
{
	return 0;
}

/**
  * just for convenient
  */

