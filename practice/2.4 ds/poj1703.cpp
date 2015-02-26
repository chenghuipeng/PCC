/** @file
  * @brief POJ1703
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


class FC
{
public:
	void operate(int N, VS o)
	{
		UF<int> uf(2*N + 1);
		VI d(N + 1, 0);
		
		for (auto& s : o)
		{
			int a = s[1] - '0', b = s[2] - '0';
			if ('D' == s[0])
			{
				uf.unite(a, b + N);
				uf.unite(b, a + N);
				
				if (0 != d[a])
				{
					uf.unite(d[a], b);
				}
				else
				{
					d[a] = b;
				}
				if (0 != d[b])
				{
					uf.unite(d[b], a);
				}
				else
				{
					d[b] = a;
				}
			}
			else
			{
				if (uf.same(a, b))
				{
					cout << "In the same gang." << endl;
				}
				else if (uf.same(a, b + N) || uf.same(a + N, b))
				{
					cout << "In different gangs." << endl;
				}
				else
				{
					cout << "Not sure yet." << endl;
				}
				
			}
		}
	}
	
};

int main(int argc, char* argv[])
{
	FC a;
	
	a.operate(5, {"A12", "D12", "A12", "D24", "A14"});
	
	return 0;
}

/**
  * just for convenient
  */

