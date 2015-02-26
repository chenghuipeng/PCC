/**
  * @file POJ3171 Cleaning Shifts 
  * @author malin
  * @date
  * @brief
  * @version
  */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

typedef pair<int, int> P;

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<P> VP;
typedef vector<bool> VB;

const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();
const int MAXREAL = numeric_limits<double>::max();
const int MINREAL = numeric_limits<double>::min();

#define FOR1(i, s, t) for (i = s; i != t; ++i)
#define FOR2(i, s, t) for (i = s; i >= t; --i)


const int INF = MAXINT/2;

class ST
{
public:
	ST(int n_)
	{
		while (n < n_) n *= 2;
		
		dat.assign(2*n - 1, INF);
	}
	
	void set(int k, int x)
	{
		k += n - 1;
		
		dat[k] = x;
		
		while (k > 0)
		{
			k = (k - 1)/2;
			
			dat[k] = min(dat[2*k + 1], dat[2*k + 2]);
		}
	}
	
	int get(int a, int b, int k, int l, int r)
	{
		if (a <= l && r <= b)
		{
			return dat[k];
		}
		else if (a < r && l < b)
		{
			return min(get(a, b, 2*k + 1, l, (l + r)/2), get(a, b, 2*k + 2, (l + r)/2, r));
		}
		else
		{
			return INF;
		}
	}
	
	int size() {return n;}
	
private:
	int n = 1;
	VI dat;
	
};


class CS
{
public:
	void solve(int N, int M, int E, VI s, VI t, VI v)
	{	
		int i = 0;
		
		// change the interval to [0, E - M + 1)
		FOR1(i, 0, N)
		{
			s[i] -= M;
			t[i] -= M;
		}
		
		E -= M; ++ E;
		
		ST st(E + 1);
		
		int n = st.size();
		
		// dp[i] := the minimal salary to converage the interval [0, i)
		VI dp(E + 1, INF); dp[0] = 0; st.set(0, 0);
		
		FOR1(i, 0, N)
		{	
			dp[t[i] + 1] = min(dp[t[i] + 1], st.get(s[i], t[i] + 1, 0, 0, n) + v[i]);
			
			st.set(t[i] + 1, dp[t[i] + 1]);
		}
		
		cout << dp[E] << endl;
	}
	
};


int main(int argc, char** argv)
{
	CS a;
	
	a.solve(3, 0, 4, {0, 3, 0}, {2, 4, 0}, {3, 2, 1});
	
	return 0;
}

/*

for convenient

*/

