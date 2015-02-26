/** @file
  * @brief Crazy Rows
  * @author malin
  * @date 2014年07月16日 星期三 17时38分05秒
  * @version 1.0
  * @note
  * greedy selection
  */

#include<iostream>
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


class CR
{
public:
	int minSwap(vector<VI> M)
	{
		VI a(M.size(), -1);

		int i, j;

		FOR1(i, 0, M.size())
		{
			FOR2(j, M.size() - 1, 0)
			{
				if (M[i][j] == 1)
				{
					a[i] = j;
					break;
				}
			}
		}

		int ans = 0;

		FOR1(i, 0, a.size())
		{
			FOR1(j, i, a.size())
			{
				if (a[j] <= i)
				{
					for (int k = j; k > i; --k)
					{
						a[k] = a[k - 1];
					}

					ans += j - i;
					break;
				}
			}
		}

		return ans;
	}

};


int main(int argc, char** argv)
{
	CR a;

	cout << a.minSwap({{1, 1, 1, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}}) << endl;
	
	return 0;
}
