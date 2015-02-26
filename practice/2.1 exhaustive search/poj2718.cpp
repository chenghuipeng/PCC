/** @file 
  * @brief POJ2718 Smallest Difference
  * @author malin
  * @date 
  * @version 1.0
  * @note
  * Just exhaustive search, noticed that if the difference between two numbers is smallest, the minus of their digits is 1.
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

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class SmallDifference
{
public:
	int difference(VI nums)
	{
		int n = nums.size()/2, ans = MAXINT;
		
		sort(nums.begin(), nums.end());
		
		int ll, rr;
		do
		{
			if (nums[n-1] != 0 && nums[nums.size()-1] != 0)
			{
				int i = 0, l = 0, r = 0;
				FOR1(i, 0, n)
				{
					l += nums[i]*pow(10, i);
				}
				FOR1(i, n, nums.size())
				{
					r += nums[i]*pow(10, i - n);
				}
				
				if (ans > abs(l-r))
				{
					ans = abs(l-r);
					ll = l;
					rr = r;
				}
			}
		}
		while (next_permutation(nums.begin(), nums.end()));
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	SmallDifference a;
	
	cout << a.difference({0, 1, 2, 3, 4, 6, 7}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

