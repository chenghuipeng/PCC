/**
  * @file POJ3254 Corn Fields 
  * @author malin
  * @date 10/08/14 10:25
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


class CF
{
public:
	int solve(vector<VI> f)
	{
		int m = f.size(), n = f[0].size();
		
		VI ss;
		
		for (int i = 0; i != 1 << n; ++i)
		{
			if (judge(i)) ss.push_back(i);
		}
		
		int s = ss.size();
		
		vector<VI> dp(m, VI(s, 0));
		 
		VI ff(m, 0);
		
		for (int i = 0; i != m; ++i)
		{
			for (int j = 0; j != n; ++j)
			{
				if (f[i][j] == 1) ff[i] += 1 << j;
			}
		}
		
		for (int i = 0; i != s; ++i)
		{
			if (subset(ss[i], ff[0])) dp[0][i] = 1;
		}
		
		for (int i = 1; i != m; ++i)
		{
			for (int j = 0; j != s; ++j)
			{
				if (subset(ss[j], ff[i]))
				{
					for (int k = 0; k != s; ++k)
					{
						if (conflict(ss[j], ss[k]))
						{
							dp[i][j] += dp[i - 1][k];
							dp[i][j] %= 100000000;
						}
					}
				}
			}
		}
		
		int ans = 0;
		
		for (auto x : dp[m - 1]) ans += x;
		
		return ans;
	}
	
private:
	bool judge(int s)
	{
		bool f = false;
		
		while (s > 0)
		{
			if (f && (s & 1))
			{
				return false;
			}
			
			f = s & 1;
			
			s >>= 1;
		}
		
		return true;
	}
	
	bool subset(int s1, int s2)
	{
		while (s1 > 0)
		{
			if ((s1 & 1) && !(s2 & 1))
			{
				return false;
			}
			
			s1 >>= 1;
			s2 >>= 1;
		}
		
		return true;
	}
	
	bool conflict(int s1, int s2)
	{
		while (s1 > 0)
		{
			if ((s1 & 1) && (s2 & 1)) return false;
			
			s1 >>= 1;
			s2 >>= 1;
		}
		
		return true;
	}
	
};


int main(int argc, char** argv)
{
	CF a;
	
	cout << a.solve({{1, 1, 1}, {0, 1, 0}}) << endl;
	
	return 0;
}

/*

for convenient

*/

