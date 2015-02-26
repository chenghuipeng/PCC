/**
  * @file Asteroids
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


class Asteroids
{
public:
	void solve(int N, VP cor)
	{
		V = N;
		
		for (int i = 0; i != cor.size(); ++i)
		{
			add_edge(cor[i].first - 1, cor[i].second + N - 1);
		}
		
		cout << bipartite_matching() << endl;
	}
	
};


int main(int argc, char** argv)
{
	Asteroids a;
	
	a.solve(3, {P(1, 1), P(1, 3), P(2, 2), P(3, 2)});
	
	return 0;
}

/*

for convenient

*/

