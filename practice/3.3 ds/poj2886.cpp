/** @file
  * @brief POJ2886 Who Gets the Most Candies
  * @author malin
  * @date 2014年08月06日 星期三 14时34分19秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "antiprime.h"
#include "../../examples/3.3/BIT.h"

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


class WGMC
{
public:
	void solve(int K, VS name, VI num)
	{
		int n = name.size();

		auto p = antiPrime::solve(n);

		int index = p.first, candy = p.second;

		BIT bit(n);

		int i = 0;

		FOR1(i, 1, n + 1) bit.update(i, 1);

		string bestName = "";

		int ni = K;

		FOR1(i, 0, n)
		{
			if (i + 1 == index)
			{
				bestName = name[ni - 1];
				break;
			}

			int mod = n - i - 1;

			int id = bit.sum(ni - 1) + num[ni - 1] + (num[ni - 1] > 0 ? 0 : 1);

			id %= mod;
			
			if (id == 0) id = mod;
			
			bit.update(ni, -1);

			// binary search
			int lb = 0, ub = n;
			
			while (ub - lb > 1)
			{
				int mid = (ub + lb)/2;

				if (bit.sum(mid) >= id)
				{
					ub = mid;
				}
				else
				{
					lb = mid;
				}
			}

			ni = ub;
		}

		cout << bestName << ' ' << candy << endl;
	}

};


int main(int argc, char** argv)
{
	WGMC a;

	a.solve(2, {"Tom", "Jack", "Marry", "Sam"}, {2, 4, -1, 1});

	return 0;
}
