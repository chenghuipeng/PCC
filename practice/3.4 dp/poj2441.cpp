/**
  * @file POJ2441 Arrange the Bulls
  * @author malin
  * @date 10/08/14 09:08
  * @brief
  * We use the state transition.
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


class AB
{
public:
	int solve(int N, int M, vector<VI> P)
	{
		int s = 1 << M;
		
		vector<VI> dp(s, VI(N + 1, 0)); dp[0][0] = 1;
		
		for (int i = 0; i != s; ++i)
		{
			for (int j = 0; j != N; ++j)
			{
				for (int k = 0; k != P[j].size(); ++k)
				{
					if (!(i >> (P[j][k] - 1) & 1))
					{
						dp[i | 1 << (P[j][k] - 1)][j + 1] += dp[i][j];
					}
				}
			}
		}
		
		int ans = 0;
		
		for (int i = 0; i != s; ++i)
		{
			ans += dp[i][N];
		}
		
		return ans;
	}
	
};


int main(int argc, char** argv)
{
	AB a;
	
	cout << a.solve(3, 4, {{1, 4}, {1, 3}, {2, 4}}) << endl;
	
	return 0;
}

/*

for convenient

*/

