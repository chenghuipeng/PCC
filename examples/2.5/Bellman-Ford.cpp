/** @file
  * @brief Bellman-Ford
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


class BF
{
	class edge
	{
	public:
		edge(int ff, int tt, int c) : f(ff), t(tt), cost(c) {}
		
		edge(VI p)
		{
			f = p[0];
			t = p[1];
			cost = p[2];
		}
		
		int f, t, cost;
		
	};
	
public:
	VI minDistance(int V, vector<VI> es, int s)
	{
		vector<edge> ES; ES.reserve(es.size());
		
		for (auto& x : es)
		{
			ES.push_back(edge(x));
		}
		
		VI d(V, MAXINT/2);
		d[s] = 0;
		
		bool update = true;
		while (update)
		{
			update = false;
			for (auto& e : ES)
			{
				if (d[e.f] != MAXINT/2 && d[e.t] > d[e.f] + e.cost)
				{
					d[e.t] = d[e.t] > d[e.f] + e.cost;
					update = true;
				}
			}
		}
		
		return move(d);
	}
	
	bool find_negative_loop(int V, vector<VI> es)
	{
		vector<edge> ES; ES.reserve(es.size());
		
		for (auto& x : es)
		{
			ES.push_back(edge(x));
		}
		
		VI d(V, 0);
		
		int i;
		
		FOR1(i, 0, V)
		{
			for (auto& e : ES)
			{
				if (d[e.t] > d[e.f] + e.cost)
				{
					d[e.t] = d[e.f] + e.cost;
					
					if (i == V - 1) return true;
				}
			}
		}
		
		return false;
	}

};

int main(int argc, char* argv[])
{
	return 0;
}

/**
  * just for convenient
  */

