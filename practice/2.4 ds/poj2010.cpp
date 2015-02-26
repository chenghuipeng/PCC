/** @file
  * @brief POJ2010
  * @author malin
  * @date
  * @version 1.0
  * The main idea is greedy select.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

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


class MUFA
{
public:
	int maxMedian(int N, int F, VP a)
	{
		sort(a.begin(), a.end());
		
		priority_queue<int, VI, greater<int> > uq;
		priority_queue<int>nq;
		priority_queue<P, VP, greater<P> > lq;
		
		int i, us = 0, ls = 0;
		
		FOR1(i, 0, a.size())
		{
			if (i < a.size() - N/2 - 1)
			{
				lq.push(P(a[i].second, i));
			}
			else if (i >= a.size() - N/2)
			{
				uq.push(a[i].second);
				
				us += a[i].second;
			}
		}
		
		FOR1(i, 0, N/2)
		{
			P p = lq.top(); lq.pop();
			
			ls += p.first;
			nq.push(p.second);
		}
		
		i = a.size() - N/2 - 1;
		
		while (us + ls +a[i].second > F)
		{	
			uq.push(a[i].second);
			us += a[i].second - uq.top(); uq.pop();
			
			-- i;
			
			if (i == nq.top())
			{
				int x = nq.top(); nq.pop();
				P p =lq.top(); lq.pop();
				
				ls += p.first - a[x].second;
				nq.push(p.second);
			}
		}
		
		return a[i].first;
	}
	
};

int main(int argc, char* argv[])
{
	MUFA a;
	
	cout << a.maxMedian(3, 70, {P(30, 25), P(50, 21), P(20, 18), P(5, 20), P(35, 30)}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

