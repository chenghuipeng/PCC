#ifndef ANTIPRIME_H
#define ANTIPRIME_H


/** @file
  * @brief find the maximal antiprime below n
  * @author malin
  * @date 2014年08月06日 星期三 11时33分50秒
  * @version 1.0
  */


#include <vector>


typedef long long ll;

class antiPrime
{
public:
	static std::pair<ll, int> solve(ll N)
	{
		n = N;

		dfs(1, 1, 1, 50);

		return std::make_pair(bestNum, maxSum);
	}

private:
	static void dfs(ll num, int sum, int k, int limit)
	{
		if (sum > maxSum)
		{
			maxSum = sum; bestNum = num;
		}
		else if (sum == maxSum && num < bestNum)
		{
			bestNum = num;
		}

		if (k >= prime.size()) return;

		int tmp = num;

		for (int i = 1; i <= limit; ++i)
		{
			if (tmp * prime[k] > n) break;

			tmp *= prime[k];

			dfs(tmp, sum*(i + 1), k + 1, i);
		}
	}

	static ll n, maxSum, bestNum;

	static std::vector<int> prime;

};

ll antiPrime::n = 0;
ll antiPrime::maxSum = 0;
ll antiPrime::bestNum = 0;
std::vector<int> antiPrime::prime = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};



#endif	// ANTIPRIME_H
