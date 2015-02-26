/** @file
  * @brief POJ1328 Radar Installation
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

#include <fstream>

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


class RI
{
public:
	int minRadars(int d, VP is)
	{
		VP ints(is.size());
		
		int i;
		FOR1(i, 0, is.size())
		{
			int xx = d*d - is[i].second*is[i].second;
			if (xx < 0)
			{
				return -1;
			}
			int x = sqrt(xx);
			ints[i].first = is[i].first - x;
			ints[i].second = is[i].first + x;
		}
		
		sort(ints.begin(), ints.end());
		
		int r = ints[0].second, ans = 1;
		FOR1(i, 1, ints.size())
		{
			if (ints[i].first > r)
			{
				++ ans;
				r = ints[i].second;
			}
			else
			{
				r = min(ints[i].second, r);
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	RI a;
	
	ifstream in("test.txt");
	
	int d;
	in >> d >> d;
	
	VP input;
	int x, y;
	while (in >> x >> y)
	{
		input.push_back(P(x, y));
	}
	
	cout << a.minRadars(d, input) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

