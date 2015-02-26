/**
  * @file POJ2836 Rectangular Covering
  * @author malin
  * @date
  * @brief
  * @version
  */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

typedef pair<int, int> P;

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<P> VP;
typedef vector<bool> VB;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();
const int MAXREAL = numeric_limits<double>::max();
const int MINREAL = numeric_limits<double>::min();

#define FOR1(i, s, t) for (i = s; i != t; ++i)
#define FOR2(i, s, t) for (i = s; i >= t; --i)


const int INF = MAXINT/2;

class RC
{
public:
	int solve(VP a)
	{
		int n = a.size();
		
		VI rs, area;
		
		int i = 0, j = 0, k = 0;
		
		FOR1(i, 0, n)
		{
			FOR1(j, i + 1, n)
			{
				int x1 = a[i].first, y1 = a[i].second, x2 = a[j].first, y2 = a[j].second;
				
				if (x1 > x2) swap(x1, x2);
				if (y1 > y2) swap(y1, y2);
				
				int A = -1;
				
				if (x1 == x2)
				{
					A = y2 - y1;
				}
				else if (y1 == y2)
				{
					A = x2 - x1;
				}
				else
				{
					A = (x2 - x1)*(y2 - y1);
				}
				
				int cnt = 0;
				
				FOR1(k, 0, n)
				{
					int x = a[k].first, y = a[k].second;
					
					if (x1 <= x && x <= x2 && y1 <= y && y <= y2) cnt += 1 << k;
				}
				
				rs.push_back(cnt);
				area.push_back(A);
			}
		}
		
		VI dp(1 << n, INF); dp[0] = 0;
			
		FOR1(i, 0, 1 << n)
		{
			FOR1(j, 0, rs.size())
			{
				dp[i | rs[j]] = min(dp[i |rs[j]], dp[i] + area[j]);
			}
		}
		
		return dp[(1 << n) - 1];
	}
};


int main(int argc, char** argv)
{
	RC a;
	
	cout << a.solve({P(1, 0), P(0, 1)}) << endl;
	
	return 0;
}

/*

for convenient

*/

