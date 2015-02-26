/** @file 
  * @brief POJ3050 Hopscotch
  * @author malin
  * @date 25/06/14 17:08
  * @version 1.0
  * @noate
  * Just use dfs, and the complexity is 5*5*4^5=25600, and the depth of the stack is 5.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <set>

#include <fstream>

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


class Hopscotch
{
public:
	int count(vector<VI> a)
	{
		A = a;
		
		out.open("aaa.txt");
		
		int i = 0, j = 0;
		FOR1(i, 0, 5)
		{
			FOR1(j, 0, 5)
			{
				VI nums(1, A[i][j]);
				dfs(i, j, nums);
			}
		}
		
		return ans;
	}
	
private:
	void dfs(int x, int y, VI nums)
	{
		if (nums.size() == 6)
		{
			if (s.find(value(nums)) == s.end())
			{
				s.insert(value(nums));
				++ ans;
			}
		}
		else
		{
			nums.push_back(0);
			int i = 0;
			FOR1(i, 0, 4)
			{
				int nx = x + dx[i], ny =  y + dy[i];
				if (0 <= nx && nx <= 4 && 0 <= ny && ny <= 4)
				{
					nums[nums.size() - 1] = A[nx][ny];
					dfs(nx, ny, nums);
				}
			}
		}
	}
	
	int value(VI nums)
	{
		int v = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			v += nums[i]*pow(10, i);
		}
		
		return v;
	}
	
	vector<VI> A;
	set<int> s;
	int ans = 0;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	ofstream out;
	
};

int main(int argc, char* argv[])
{
	Hopscotch a;
	
	vector<VI> nums;
	
	ifstream in("test.txt");
	
	VI tmp;
	int i = 0, n;
	while (in >> n)
	{
		tmp.push_back(n);
		++i;
		if (i == 5)
		{
			nums.push_back(tmp);
			tmp.clear();
			i = 0;
		}
	}
	
	cout << a.count(nums) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

