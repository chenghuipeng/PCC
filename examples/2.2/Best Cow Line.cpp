/** @file 
  * @brief Best Cow Line
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

typedef pair<int, int> P;

#define FOR1(i, s, n) for (i = s; i != n; ++i)

#define FOR2(i, s, n) for (i = s; i >= n; --i)


class BCL
{
public:
	string smallest(string S)
	{
		int l = 0, r = S.size() - 1;
		string ans;
		
		while (l <= r)
		{
			if (S[l] < S[r])
			{
				ans += S[l++];
			}
			else if (S[l] > S[r])
			{
				ans += S[r--];
			}
			else
			{
				int tl = l, tr = r;
				while (S[tl] == S[tr] && tr > tl)
				{
					++ tl;
					-- tr;
				}
				
				ans += S[tl] < S[tr] ? S[l++] : S[r--];
			}
			
			// The solution of the book
			bool left = false;
			for (int i = 0; l + 2*i <= r; ++i)
			{
				if (S[l+i] < S[r-i])
				{
					left = true;
					break;
				}
				if (S[l+i] > S[r-i])
				{
					left = false;
					break;
				}
			}
			
			ans += left ? S[l++] : S[r--];
		}
		
		return ans;
	}
	
};

int main(int argc, char* argv[])
{
	BCL a;
	
	cout << a.smallest("ACDBCB") << endl;
	
	return 0;
}

/**
  * just for convenient
  */

