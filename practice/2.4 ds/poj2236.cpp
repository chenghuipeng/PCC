/** @file
  * @brief POJ2236
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


class WN
{
public:
	void operate(int N, int d, VP c, VS o)
	{
		UF<int> uf(N+1);
		vector<bool> f(N+1, false);
		
		int n = 0;
		
		for (auto s : o)
		{
			if ('O' == s[0] && n < N)
			{
				++ n;
				
				int i, x = s[1] - '0';
				
				f[x] = true;
				
				FOR1(i, 0, N)
				{
					if (i + 1 != x && distance(c[i], c[x-1]) <= d && f[i+1])
					{
						uf.unite(i+1, x);
						break;
					}
				}
			}
			else if ('S' == s[0])
			{
				cout << (uf.same(s[1] - '0', s[2] - '0') ? "SUCCESS" : "FAIL") << endl;
			}
		}
	}
	
private:
	int distance(P& x, P& y)
	{
		return sqrt(pow((x.first - y.first), 2) + pow((x.second - y.second), 2));
	}
	
};

int main(int argc, char* argv[])
{
	WN a;
	
	a.operate(4, 1, {P(0, 1), P(0, 2), P(0, 3), P(0, 4)}, {"O1", "O2", "O4", "S14", "O3", "S13"});
	
	return 0;
}

/**
  * just for convenient
  */

