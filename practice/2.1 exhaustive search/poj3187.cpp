/** @file 
  * @brief POJ3187 Backward Digit Sums
  * @author malin
  * @date 
  * @version 1.0
  * @note
  * The complexity is n!.
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


class BDS
{
public:
	VI origin(int N, int sum)
	{
		VI ans(N);
		for (int i = 0; i != N; ++i) ans[i] = i + 1;
		
		do
		{
			int s = 1, i, j;
			VI tmp = ans;
			FOR1(i, 0, N)
			{
				FOR2(j, N-1, s)
				{
					tmp[j] = tmp[j] + tmp[j-1];
				}
				
				++ s;
			}
			
			if (tmp[N-1] == sum) break;
		}
		while (next_permutation(ans.begin(), ans.end()));
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	BDS a;
	
	auto ans = a.origin(4, 16);
	
	for (auto x : ans) cout << x << ' ';
	
	cout << endl;
	
	return 0;
}

/**
  * just for convenient
  */

