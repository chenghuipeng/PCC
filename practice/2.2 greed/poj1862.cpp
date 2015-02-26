/** @file
  * @brief POJ1862 Stripies
  * @author malin
  * @date
  * @version 1.0
  * The main ieda is that always selecting the biggest two stripies to be a new one
  */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iomanip>

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


class Stripies
{
public:
	double minWeight(VI ws)
	{
		priority_queue<double> que(ws.begin(), ws.end());
		
		while (que.size() > 1)
		{
			double a = que.top(); que.pop();
			double b = que.top(); que.pop();
			
			que.push(2*sqrt(a*b));
		}
		
		return que.top();
	}
	
};

int main(int argc, char* argv[])
{
	Stripies a;
	
	cout <<  setprecision(3) << a.minWeight({72, 30, 50}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

