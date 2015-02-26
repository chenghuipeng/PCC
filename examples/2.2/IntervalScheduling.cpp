/** @file 
  * @brief Interval scheduling
  * @author malin
  * @date 
  * @version 1.0
  * @bote
  * The greedy choice is selecting the interval either has a smallest end time or has a largest start time.
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


class IS
{
public:
	int maxInterval(VI s, VI t)
	{
		vector<P> ins(s.size());
		
		int i = 0;
		FOR1(i, 0, s.size())
		{
			ins[i] = P(t[i], s[i]);
		}
		
		sort(ins.begin(), ins.end());
		
		int tt = 0, ans = 0;
		FOR1(i, 0, ins.size())
		{
			if (tt < ins[i].second)
			{
				++ ans;
				tt = ins[i].first;
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	IS a;
	
	cout << a.maxInterval({1, 2, 4, 6, 8}, {3, 5, 7, 9, 10}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

