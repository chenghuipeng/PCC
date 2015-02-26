/** @file
  * @brief POJ3262 Protecting the Flowers
  * @author malin
  * @date
  * @version 1.0
  * @note
  * The main idea is that we always transport the cow with the minimal "T/D" value. The proof is given below.
  * 1) First, we determine the "greedy choice property".
  	   Assume that the cow has the minimal "T/D" is at the ith position of the transport sequence(the cow in kth position is the
	   first k cow will be transport), and if we exchange it with the i-1 cow, the total number of flowers will be increased by 
	   Ti*Di-1 - Ti1*Di, as we know that Ti/Di <= Ti-1/Di-1, so the total number becomes smaller, so we can draw a conclusion that
	   there must be exiting an optimal solution which first position is the cow with the minimal "T/D' value.
	2) Then, we determine that this problem has the "optimal substructure".
	   If there is a optimal solution of the cows except the one with minimal "T/D", we can put the minimal cow at the first position to produce
	   a global optimal solution, just use the "Cut and Paste" method.
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


class PtF
{
public:
	int minFlowers(VP in)
	{
		vector<pair<double, int> > a(in.size());
		
		int i;
		FOR1(i, 0, in.size())
		{
			a[i].first = (double)in[i].first/in[i].second;
			a[i].second = i;
		}
		
		sort(a.begin(), a.end());
		
		long long d = 0, ans = 0;
		FOR2(i, a.size() - 2, 0)
		{
			ans += 2 * (d += in[a[i+1].second].second) * in[a[i].second].first;
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	PtF a;
	
	cout << a.minFlowers({P(3, 1), P(2, 5), P(2, 3), P(3, 2), P(4, 1) ,P(1, 6)}) << endl;
	
	return 0;
}

/**
  * just for convenient
  */

