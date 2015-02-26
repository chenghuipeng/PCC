/** @file
  * @brief Algorithm of Prime.
  * @author malin
  * @date 2014年07月14日 星期一 10时06分49秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <map>

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


class Prime
{
public:
	static bool is_prime(int n)
	{
		for (int i = 2; i*i <= n; ++i)
		{
			if (n%i == 0) return false;
		}

		return n != 1; // 1 is not prime.
	}

	static VI divisor(int n)
	{
		VI ans;
		for (int i = 1; i*i <= n; ++i) // A number's divisor set includes 1 and itself.
		{
			if (n%i == 0)
			{
				ans.push_back(i);
				if (i != n/i)
				{
					ans.push_back(n/i);
				}
			}
		}

		return move(ans);
	}

	static map<int, int> prime_factor(int n)
	{
		map<int, int> ans;

		for (int i = 2; i*i <= n; ++i)
		{
			while (n%i == 0)
			{
				++ ans[i];
				n /= i;
			}
		}

		if (n != 1) ++ ans[n];

		return ans;
	}

	static int sieve(int n)
	{
		VI prime;
		vector<bool> is_prime(n + 1, true);
		is_prime[0] = is_prime[1] = false;	// 0 and 1 are not prime.

		int ans = 0;

		for (int i = 2; i <= n; ++i)
		{
			if (is_prime[i])
			{
				prime.push_back(i);
				++ ans;
				for (int j = 2*i; j <= n; j += i)
				{
					is_prime[j] = false;
				}
			}
		}

		return ans;
	}

	// The segment is [a, b)
	static int segment_sieve(int a, int b)
	{
		vector<bool> is_prime(b - a, true), is_prime_small(sqrt(b) + 2, true);
		is_prime_small[0] = is_prime_small[1] = false;

		for (int i = 2; i*i < b; ++i)
		{
			if (is_prime_small[i])
			{
				// Sieve [2, sqrt(b))
				for (int j = 2*i; j*j < b; j += i)
				{
					is_prime_small[j] = false;
				}
				// Sieve [a, b)
				for (int j = max(2, (a + i - 1)/i)*i; j < b; j += i)
				{
					is_prime[j - a] = false;
				}
			}
		}

		int ans = 0;

		for (auto x : is_prime)
		{
			if (x) ++ ans;
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	cout << boolalpha << Prime::is_prime(13) << endl;

	auto v = Prime::divisor(100);

	for (auto x : v) cout << x << ' ';
	cout << endl;

	auto m = Prime::prime_factor(100);

	for (auto x : m) cout << x.first << '-' << x.second << ' ';
	cout << endl;

	cout <<Prime::sieve(11) << endl;

	cout << Prime::segment_sieve(22, 37) << endl;

	return 0;
}
