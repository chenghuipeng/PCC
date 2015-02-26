/** @file
  * @brief food chain
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
#include "UF.h"

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
	int count(int N, vector<VI> a)
	{
		n = N;
		
		uf.init(3*n + 1);
		
		int ans = 0;
		
		for (auto& x : a)
		{
			if (x[1] < 1 || N < x[1] || x[2] < 1 || N < x[2])
			{
				++ ans;
				continue;
			}
			
			if (x[0] == 1)
			{
				if (!eat(x[1], x[2]) && !eat(x[2], x[1]))
				{
					unite1(x[1], x[2]);
				}
				else
				{
					++ ans;
				}
			}
			else
			{
				if (same(x[1], x[2]) || eat(x[2], x[1]))
				{
					++ ans;
				}
				else
				{
					unite2(x[1], x[2]);
				}
			}
		}
		
		return ans;
	}
	
private:
	bool eat(int x, int y)
	{
		return uf.same(x, n + y) || uf.same(n + x, 2*n + y) || uf.same(2*n + x, y);
	}
	
	void unite1(int x, int y)
	{
		uf.unite(x, y);
		uf.unite(n + x, n + y);
		uf.unite(2*n + x, 2*n + y);
	}
	
	void unite2(int x, int y)
	{
		uf.unite(x, n + y);
		uf.unite(n + x, 2*n + y);
		uf.unite(2*n + x, y);
	}
	
	bool same(int x, int y)
	{
		return uf.same(x, y) || uf.same(n + x, n + y) || uf.same(2*n + x, 2*n + y);
	}
	
	int n;
	UF<int> uf;
	
};

int main(int argc, char* argv[])
{
	FC a;
	
	cout << a.count(100, {{1, 101, 1}, {2, 1, 2}, {2, 2, 3}, {2, 3, 3}, {1, 1, 3}, {2, 3, 1}, {1, 5, 5}}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

