/** @file
  * @brief POJ3190 Stall Reservations
  * @author malin
  * @date
  * @version 1.0
  * @note
  * Using the interval tree to maintenance the intervals.
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <set>

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


class Interval
{
public:
	Interval(int x = 0, int y = 0) : f(x), s(y) {}
	
	int f;
	int s;
	
};

bool operator < (const Interval& lhs, const Interval& rhs)
{
	return lhs.s < rhs.f;
}

bool operator > (const Interval& lhs, const Interval& rhs)
{
	return lhs.f > rhs.s;
}

bool operator == (const Interval& lhs, const Interval& rhs)
{
	return lhs.f <= rhs.s && rhs.f <= lhs.s;
}

class SR
{
public:
	VI assign(VP ins)
	{
		vector<set<Interval> > ss;
		VI m(ins.size(), 0);
		
		int i = 0;
		FOR1(i, 0, ins.size())
		{
			Interval in(ins[i].first, ins[i].second);
			bool f = false;
			int j;
			FOR1(j, 0, ss.size())
			{
				if (ss[j].find(in) == ss[j].end())
				{
					f = true;
					ss[j].insert(in);
					m[i] = j + 1;
					break;
				}
			}
			
			if (!f)
			{
				set<Interval> tmp;
				tmp.insert(in);
				ss.push_back(move(tmp));
				m[i] = ss.size();
			}
		}
		
		return move(m);
	}
	
};

int main(int argc, char* argv[])
{
	SR a;
	
	auto x = a.assign({P(1, 10), P(2, 4), P(3, 6), P(5, 8), P(4, 7)});
	
	for (auto e : x)
	{
		cout << e << ' ';
	}
	cout << endl;
	
	return 0;
}

/**
  * just for convenient
  */

