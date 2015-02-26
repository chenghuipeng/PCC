/** @file
  * @brief POJ3040 Allowance
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


class Allowance
{
public:
	int count(int c, VP cions)
	{
		sort(cions.begin(), cions.end());
		
		int sum = accumulate(cions.begin(), cions.end(), 0,
			[](int iv, const P& p){return iv + p.first*p.second;});
		int ans = 0, s = 0;
		
		while (s < sum)
		{
			int n = c, i;
			FOR2(i, cions.size()-1, 0)
			{
				int t = min(n/cions[i].first, cions[i].second);
				cions[i].second -= t;
				n -= t*cions[i].first;
			}
			
			s += c;
			if (n > 0)
			{
				i = 0;
				while (cions[i++].second == 0);
				cions[--i].second -= 1;
				
				s += cions[i].first - n;
			}
			
			++ ans;
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	Allowance a;
	
	cout << a.count(6, {P(10, 1), P(1, 100), P(5, 120)}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

