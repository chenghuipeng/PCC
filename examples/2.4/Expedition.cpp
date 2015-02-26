/** @file
  * @brief Expedition
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
#include <queue>

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


class Expedition
{
public:
	int minNum(VI A, VI B, int P, int L)
	{
		A.push_back(L); B.push_back(0);
		
		priority_queue<int> que;
		
		int i, v = P, ans = 0;
		
		FOR1(i, 0, A.size())
		{
			while (!que.empty() && (v - A[i] < 0))
			{
				v += que.top();
				que.pop();
				
				++ ans;
			}
			if (v - A[i] < 0)
			{
				ans = -1;
				break;
			}
			
			que.push(B[i]);
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	Expedition a;
	
	cout << a.minNum({10, 14, 20, 21}, {10, 5, 2, 4}, 10, 25) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

