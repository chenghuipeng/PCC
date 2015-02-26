/** @file 
  * @brief Sarauman's Army
  * @author malin
  * @date 
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

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class SA
{
public:
	int count(int r, VI nodes)
	{
		int ans = 0;
		
		sort(nodes.begin(), nodes.end());
		
		int i = 0;
		while (i != nodes.size())
		{
			int s = nodes[i++];
			
			while (i < nodes.size() && nodes[i] - s <= r) ++ i;
			
			int p = nodes[i-1];		// The marked point
			
			while (i < nodes.size() && nodes[i] - p <= r) ++ i;
			
			++ ans;
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	SA a;
	
	cout << a.count(10, {1, 7, 15, 20, 30, 50}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

