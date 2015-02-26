/**
  * @file POJ3411 Paid Roads 
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

class PR
{
public:
	int solve(int N, vector<VI> R)
	{
		vector<VI> G(N);
		
		int i = 0, j = 0;
		
		FOR1(i, 0, R.size())
		{
			-- R[i][0]; -- R[i][1]; -- R[i][2];
			G[R[i][0]].push_back(i);
		}
		
		vector<VI> dp(1 << N, VI(N, INF)); dp[1][0] = 0;
		
		int ans = INF;
		
		FOR1(i, 1, 1 << N)
		{
			ans = min(ans, dp[i][N - 1]);
			
			if (i & 1)
			{
				FOR1(j, 0, N)
				{
					for (auto x : G[j])
					{
						if (i >> R[x][1] & 1) continue;
						
						if (i >> R[x][2] & 1)
						{
							dp[i | (1 << R[x][1])][R[x][1]] = min(dp[i | (1 << R[x][1])][R[x][1]], dp[i][j] + R[x][3]);
						}
						else
						{
							dp[i | (1 << R[x][1])][R[x][1]] = min(dp[i | (1 << R[x][1])][R[x][1]], dp[i][j] + R[x][4]);
						}
					}
				}
			}
		}
		
		for (auto& v : dp)
		{
			for (auto x : v) cout << x << ' ';
			
			cout << endl;
		}
		
		return ans;
	}
	
};


int main(int argc, char** argv)
{
	PR a;
	
	cout << a.solve(4, {{1, 2, 1, 10, 10}, {2, 3, 1, 30, 50}, {3, 4, 3, 80, 80},
					{2, 1, 2, 10, 10}, {1, 3, 2, 10, 50}}) << endl;
	return 0;
}

/*

for convenient

*/

