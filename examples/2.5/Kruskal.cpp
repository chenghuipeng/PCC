/** @file
  * @brief Kruskal
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


class edge
{
public:
	edge(VI p)
	{
		f = p[0]; t = p[1]; c = p[2];
	}
	
	int f, t, c;
};

class Kruskal
{
public:
	int minCost(vector<VI> g, int V)
	{
		vector<edge> G;
		
		for (auto& v : g)
		{
			G.push_back(edge(v));
		}
		
		sort(G.begin(), G.end(), [](const edge& lhs, const edge& rhs){return lhs.c < rhs.c;});
		
		UF<int> uf(V);
		
		int ans = 0;
		
		for (auto& e : G)
		{
			if (!uf.same(e.f, e.t))
			{
				uf.unite(e.f, e.t);
				ans += e.c;
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	return 0;
}

/**
  * just for convenient
  */

