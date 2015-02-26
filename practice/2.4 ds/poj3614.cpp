/** @file
  * @brief POJ3614
  * @author malin
  * @date
  * @version 1.0
  * The main idea is greedy selecting. We always selete the sunscreen lotion bottle with biggest SPF
  	for the cow with the biggest SPFmax if possible.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>
#include <functional>

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

class cmp
{
public:
	bool operator () (const P& lhs, const P& rhs)
	{
		return lhs.second < rhs.second;
	}
};

class SS
{
public:
	int count(VP c, VP s)
	{
		priority_queue<P,VP, cmp> cq(c.begin(), c.end());
		priority_queue<P> sq(s.begin(), s.end());
		
		int ans = 0;
		while (!cq.empty())
		{
			P c = cq.top(); cq.pop();
			
			while (!sq.empty())
			{
				P& s = const_cast<P&>(sq.top());
				
				if (s.first > c.second)
				{
					sq.pop();
				}
				else
				{
					if (c.first <= s.first <= c.second)
					{
						++ ans;
						if (-- s.second == 0)
						{
							sq.pop();
						}
					}
					break;
				}	
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	SS a;
	
	cout << a.count({P(3, 10), P(2, 5), P(1, 5)}, {P(6, 2), P(4, 1)}) << endl;
	return 0;
}

/**
  * just for convenient
  */

