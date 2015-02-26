/** @file
  * @brief Conscription
  * @author malin
  * @date
  * @version 1.0
  * @note
  * The two most important things are the praph is a forrest and the weight of edge is negative, so we can only use Kruskal method.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

#include "../2.4/UF.h"

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


class Conscription
{
public:
	int minCost(vector<VI> G, int N, int M)
	{
		UF<int> uf(N + M);
		
		for (auto& v : G)
		{
			v[1] += N;
			v[2] *= -1;
		}
		
		sort(G.begin(), G.end(), [](const VI& lhs, const VI& rhs){return lhs[2] < rhs[2];});
		
		int ans = 0;
		
		for (auto& e : G)
		{
			if (!uf.same(e[0], e[1]))
			{
				ans += e[2];
				uf.unite(e[0], e[1]);
			}
		}
		
		return (N + M)*10000 + ans;
	}
	
};

int main(int argc, char* argv[])
{
	Conscription a;
	
	cout << a.minCost({{4, 3, 6831}, {1, 3, 4583}, {0, 0, 6592}, {0, 1, 3063}, {3, 3, 4975}, {1, 3, 2049}, {4, 2, 2104}, {2, 2, 781}}, 5, 5) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

