/** @file
  * @brief Bipartite Graph Judge
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
#include <stack>

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


class BGJ
{
public:
	void judge(vector<VI> g)
	{
		G = g; C.resize(G.size(), -1);
		
		int i;
		
		FOR1(i, 0, G.size())
		{
			if (C[i] == -1)
			{
				if (!dfs(i))
				{
					cout << "No" << endl;
					return;
				}
			}
		}
		
		cout << "Yes" << endl;
	}
	
private:
	bool dfs(int i)
	{
		stack<int> s;
		s.push(i);
		
		C[i] = 0;
		
		while (!s.empty())
		{
			i = s.top(); s.pop();
			for (auto x : G[i])
			{
				if (C[x] == C[i])
				{
					return false;
				}
				else if (C[x] == -1)
				{
					C[x] = (C[i] + 1)%2;
					s.push(x);
				}
			}
		}
		
		return true;
	}
	
	vector<VI> G;
	VI C;
	
};

int main(int argc, char* argv[])
{
	BGJ a;
	
	a.judge({{1, 3}, {0, 2}, {1, 3}, {0, 2}});
	
	return 0;
}

/**
  * just for convenient
  */

