/** @file
  * @brief POJ2395 Out of Hay
  * @author malin
  * @date 2014年07月13日 星期日 19时14分27秒
  * @version 1.0
  * The answer is the longest road in the MST.
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include "../../examples/2.4/UF.h"

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


class OoH
{
public:
	int minLongestRoad(int N, vector<VI> M)
	{
		UF<int> uf(N);

		sort(M.begin(), M.end(), [](const VI& lhs, const VI& rhs){return lhs[2] <rhs[2];});

		int ans = 0;

		for (auto& e : M)
		{
			if (!uf.same(e[0] - 1, e[1] - 1))
			{
				ans = max(ans, e[2]);
				uf.unite(e[0] - 1, e[1] - 1);
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	OoH a;

	cout << a.minLongestRoad(3, {{1, 2, 23}, {2, 3, 1000}, {1, 3, 43}}) << endl;

	return 0;
}
