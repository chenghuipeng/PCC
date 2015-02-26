/** @file 
  * @brief POJ2718 Smallest Difference
  * @author malin
  * @date 
  * @version 1.0
  * @note
  * In this version, we use a certainty algorithm instead of exhaustive search.
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
		sort(nums.begin(), nums.end());
		
		int b = 0, s = 0;
		if (nums.size()%2 == 0)
		{
			int d = 10, i = 0;
			for (int j = 0; j != nums.size() - 1; ++j)
			{
				if (nums[j] != 0)
				{
					if (nums[j+1] - nums[j] < d)
					{
						d = nums[j+1] - nums[j];
						i = j;
					}
				}
			}
			
			b += nums[i+1]*pow(10, nums.size()/2 - 1);
			s += nums[i]*pow(10, nums.size()/2 - 1);
			nums.erase(nums.begin() + i, nums.begin() + i + 2);
			
			for (int j = 0; j != nums.size()/2; ++j)
			{
				s += nums[j + nums.size()/2]*pow(10, j);
				b += nums[j]*pow(10, nums.size()/2 - j - 1);
			}
		}
		else
		{
			int i = nums[0] == 0 ? 1 : 0;
			b += nums[i]*pow(10, nums.size()/2);
			nums.erase(nums.begin() + i);
			
			for (int j = 0; j != nums.size()/2; ++j)
			{
				b += nums[j]*pow(10, nums.size()/2 - j - 1);
				s += nums[j + nums.size()/2]*pow(10, j);
			}
		}
		
		return b - s;
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

