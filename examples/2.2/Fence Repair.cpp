/** @file
  * @brief Fence Repair
  * @author malin
  * @date
  * @version 1.0
  * @note
  * The same to Huffman code
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


class FR
{
public:
	int minCost(VI  fences)
	{
		int a, b, ans = 0, n = fences.size();
		while (n > 1)
		{		
			a = 0, b = 1;
			if (fences[a] > fences[b]) swap(a, b);
			
			// find the minimal two elements
			for (int i = 2; i != n; ++i)
			{
				if (fences[i] < fences[a])
				{
					b = a;
					a = i;
				}
				else if (fences[i] < fences[b])
				{
					b = i;
				}
			}
			
			int t = fences[a] + fences[b];
			ans += t;
			
			fences[a] = t;
			fences[b] = fences[--n];
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

