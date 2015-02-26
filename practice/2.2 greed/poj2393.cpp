/** @file
  * @brief POJ2393 Yogurt factory
  * @author malin
  * @date
  * @version 1.0
  * @note
  * The main idea is that if (C[i]+(j-i)*s)<C[j] (i < j), we can deliveries Y[j] units of yogurt in the ith week, and 
  * if (C[i]+(j-i)*s)>=C[j] (i < j), we can determine that for all k(i<k<j), (C[k]+(j-k)*s)>=C[j].
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


class YF
{
public:
	int minCost(int s, VP plan)
	{
		int i = 0;
		long long ans = 0;
		while (i < plan.size())
		{
			ans += plan[i].first*plan[i].second;
			int ii = i++;
			while ((plan[ii].first + (i - ii)*s) < plan[i].first && i < plan.size())
			{
				ans += (plan[ii].first + (i - ii)*s)*plan[i].second;
				++ i;
			}
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	YF a;
	
	cout << a.minCost(5, {P(88, 200), P(89, 400), P(97, 300), P(91, 500)}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

