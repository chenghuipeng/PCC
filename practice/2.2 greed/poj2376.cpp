/** @file
  * @brief POJ2376 Cleaning Shifts
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


class CS
{
public:
	int minCows(int N, int T, VP cows)
	{
		sort(cows.begin(), cows.end(),
			[](const P& lhs, const P& rhs)
				{return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second < rhs.second;});
				
		int i = 0, up = cows[0].second, ans = 1;
		FOR1(i, 1, cows.size())
		{
			if (cows[i].first > cows[i-1].second)
			{
				return -1;
			}
			if (cows[i].first == cows[i-1].first)
			{
				up = cows[i].second;
			}
			else
			{
				if (cows[i].first > up)
				{
					up = cows[--i].second;
					++ ans;
				}
			}
		}
		
		if (cows[0].first != 1 || (up < T && cows[cows.size()-1].second < T))
		{
			return -1;
		}
		
		if (up < T) ++ ans;
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	CS a;
	
	ifstream in("test.txt");
	
	int n, t;
	
	in >> n >> t;
	
	VP input;
	int f, s;
	while (in >> f >> s)
	{
		input.push_back(P(f, s));
	}
	
	cout << a.minCows(n, t, input) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

