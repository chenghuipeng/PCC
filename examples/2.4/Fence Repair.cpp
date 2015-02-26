/** @file
  * @brief Fence Repair
  * @author malin
  * @date
  * @version 1.0
  * @note
  * The same to Huffman code, using the minimum heap
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>

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


class FR
{
public:
	int minCost(VI  fences)
	{
		priority_queue<int, VI, greater<int> > que(fences.begin(), fences.end());
		
		int a, b, ans = 0;
		while (que.size() > 1)
		{
			a = que.top(); que.pop(); b = que.top(); que.pop();
			ans += a + b;
			que.push(a+b);
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	FR a;
	
	cout << a.minCost({8, 5, 8}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

