/** @file
  * @brief POJ3181 Dollar Days
  * @author malin
  * @date
  * @version 1.0
  * The same to complete knapsack, The only thing need to pay attention to is that we must use the "BigInt".
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include <iomanip>

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

const long long MAXLL = 1e18;

class BigInt
{
public:
	BigInt(long long a = 0, long long b = 0) : h(a), l(b) {}
	
	friend const BigInt operator + (const BigInt& lhs, const BigInt& rhs)
	{
		BigInt res;
		
		long long s = lhs.l + rhs.l;
		
		res.l = s%MAXLL;
		
		res.h = lhs.h + rhs.h + (s >= MAXLL);
		
		return res;
	}
	
	friend ostream& operator << (ostream& lhs, const BigInt& rhs)
	{
		lhs << rhs.h << setw(18) << rhs.l;
	}

	long long h, l;
	
};

class DD
{
public:
	 BigInt count(int N, int K)
	{
		vector<BigInt> dp(N + 1);
		dp[0].l = 1;
		
		int i, j;
		
		FOR1(i, 0, K)
		{
			FOR1(j, i+1, N + 1)
			{
				dp[j] = dp[j] + dp[j-(i+1)];
			}
		}
		
		return move(dp[N]);
	}
	
};

int main(int argc, char* argv[])
{
	DD a;
	
	cout << a.count(796, 135) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

