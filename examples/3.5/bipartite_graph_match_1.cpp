/**
  * @file bipartite graph match 
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

#include "max_flow_f.h"

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


class BGM
{
public:
	void solve(int N, int K, vector<vector<bool> > G)
	{
		int s = N + K, t = s + 1;
		
		for (int i = 0; i != N; ++i)
		{
			add_edge(s, i, 1);
		}
		for (int i = 0; i != K; ++i)
		{
			add_edge(N + i, t, 1);
		}
		
		for (int i = 0; i != N; ++i)
		{
			for (int j = 0; j !=K; ++j)
			{
				if (G[i][j])
				{
					add_edge(i, N + j, 1);
				}
			}
		}
		
		cout <<  max_flow(s, t) << endl;
	}
	
};


int main(int argc, char** argv)
{
	return 0;
}

/*

for convenient

*/

