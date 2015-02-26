/** @file
  * @brief Layout
  * @author malin
  * @date 2014年07月12日 星期六 10时02分03秒
  * @version 1.0
  */

#include<iostream>
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


class edge
{
public:
	edge(int x, int y, int z) : f(x), t(y), c(z) {}
	
	int f, t, c;

};

class Layout
{
public:
	int maxDistance(int N, vector<VI> ML, vector<VI> MD)
	{
		vector<edge> G; G.reserve(N + ML.size() + MD.size());

		int i;

		FOR1(i, 1, N)
		{
			G.push_back(edge(i, i - 1, 0));
		}

		FOR1(i, 0, ML.size())
		{
			G.push_back(edge(ML[i][0] - 1, ML[i][1] - 1, ML[i][2]));
		}

		FOR1(i, 0, MD.size())
		{
			G.push_back(edge(MD[i][1] - 1, MD[i][0] - 1, -MD[i][2]));
		}

		VI d(N, MAXINT/2); d[0] = 0;

		i = 0;
		bool update = true;

		while (update)
		{
			if (++ i > N)
			{
				return -1;
			}
			update = false;

			for (auto& e : G)
			{
				if (d[e.t] > d[e.f] + e.c)
				{
					d[e.t] = d[e.f] + e.c;
					update = true;
				}
			}
		}

		return d[N-1] == MAXINT/2 ? -2 : d[N-1];
	}

};

int main(int argc, char** argv)
{
	Layout a;

	cout << a.maxDistance(4, {{1, 3, 10}, {2, 4, 20}}, {{2, 3, 3}}) << endl;

	return 0;
}
