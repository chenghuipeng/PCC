/** @file
  * @brief POJ1017 Packets
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
typedef vector<pair<int, int> > VP;

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class Packets
{
public:
	int count(VI pros)
	{
		int a[4] = {0, 5, 3, 1};
		
		int ans = pros[5] + pros[4] + pros[3] + (pros[2] + 3)/4;
		
		int n2 = 5*pros[3] + a[pros[2]%4]; // The number of "2*2" needed to fill "4*4" and "3*3"
		
		if (pros[1] > n2)
		{
			ans += (pros[1] - n2 + 8)/9;
		}
		
		int n1 = ans*36 - pros[5]*6 - pros[4]*5 - pros[3]*4 - pros[2]*3 - pros[1]*2; // The number of "1*1" needed to fill exited packets
		
		if (pros[0] > n1)
		{
			ans += (pros[0] - n1 + 35)/36;
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	Packets a;
	
	cout << a.count({7, 5, 1, 0, 0, 0}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

