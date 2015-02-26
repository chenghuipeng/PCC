/** @file
  * @brief POJ3259 Wormholes
  * @author malin
  * @date 2014年07月12日 星期六 16时39分47秒
  * @version 1.0
  * The main idea is that find whether the graph has a negative loop or not. We cam use the Bellman-Ford method.
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


class Wormholes
{
public:
	string find_negtive_loop(int N, vector<VI> M, vector<VI> W)
	{
		int n = M.size();
		M.resize(2*n + W.size());

		copy(M.begin(), M.begin() + n, M.begin() + n);
		copy(W.begin(), W.end(), M.begin() + 2*n);

		int i;

		FOR1(i, n, 2*n)
		{
			swap(M[i][0], M[i][1]);
		}

		FOR1(i, 2*n, M.size())
		{
			M[i][2] *= -1;
		}

		VI d(N, 0);

		FOR1(i, 0, N)
		{
			for (auto& e : M)
			{
				if (d[e[1]] > d[e[0]] + e[2])
				{
					d[e[1]] = d[e[0]] + e[2];
					
					if (i == N - 1)
					{
						return "YES";
					}
				}
			}
		}

		return "No";
	}

};

int main(int argc, char** argv)
{
	Wormholes a;

	cout << a.find_negtive_loop(3, {{0, 3, 200}}, {{0, 1, 1}, {1, 2, 1}, {2, 1, 1}}) << endl;

	return 0;
}
