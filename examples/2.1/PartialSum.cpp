/** @file 
  * @brief Partial Sum
  * @author malin
  * @date 24/06/14 10:49
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

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class PartialSum
{
public:
	bool solve(vector<int> nums, int k)
	{
		Nums = nums; K = k; n = nums.size();
		
		return dfs(0, 0); // At the beginnig we haven't use any numbers, so "i = 0" and "sum = 0". 
	}
	
private:
	bool dfs(int i, int sum)
	{
		if (i == n) return sum == K;
		
		if (dfs(i+1, sum + Nums[i])) return true;
		
		if (dfs(i+1, sum)) return true;
		
		return false;
	}
	
	VI Nums;
	int K, n;
	
};

int main(int argc, char* argv[])
{
	PartialSum a;
	
	cout << a.solve({1, 2, 4, 7}, 15) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

