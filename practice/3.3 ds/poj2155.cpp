/** @file
  * @brief POJ2155 Matrix
  * @author malin
  * @date 2014年08月05日 星期二 14时43分12秒
  * @version 1.0
  */

#include<iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <math.h>

#include "../../examples/3.3/DBIT.h"

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


class Matrix
{
public:
	void solve(int N, vector<char> T, VI X1, VI Y1, VI X2, VI Y2)
	{
		DBIT b0(N, N), b1(N, N), b2(N, N), b3(N, N);

//		DBIT db(N, N);

		for (int i = 0; i != T.size(); ++i)
		{
			int x1 = X1[i], x2 = X2[i], y1 = Y1[i], y2 = Y2[i];

			if (T[i] == 'C')
			{
//				db.update(x1, y1, 1);
//				db.update(x1, y2 + 1, -1);
//				db.update(x2 + 1, y1, -1);
//				db.update(x2 + 1, y2 + 1, 1);

				++ x2; ++ y2;

				b0.update(x1, y1, (x1 - 1)*(y1 - 1));
				b1.update(x1, y1, 1);
				b2.update(x1, y1, 1 - y1);
				b3.update(x1, y1, 1 - x1);

				b0.update(x2, y1, -(x2 - 1)*(y1 - 1));
				b1.update(x2, y1, -1);
				b2.update(x2, y1, y1 - 1);
				b3.update(x2, y1, x2 - 1);

				b0.update(x1, y2, -(y2 - 1)*(x1 - 1));
				b1.update(x1, y2, -1);
				b2.update(x1, y2, y2 - 1);
				b3.update(x1, y2, x1 - 1);

				b0.update(x2, y2, (x2 - 1)*(y2 - 1));
				b1.update(x2, y2, 1);
				b2.update(x2, y2, 1 - y2);
				b3.update(x2, y2, 1 - x2);
			}
			else
			{
//				cout << (db.query(x1, y1) & 1) << endl;

				int c0 = b0.query(x1, y1) + b1.query(x1, y1)*x1*y1 + b2.query(x1, y1)*x1 + b3.query(x1, y1)*y1;
				int c1 = b0.query(x1 - 1, y1) + b1.query(x1 - 1, y1)*(x1 - 1)*y1 +
						 b2.query(x1 - 1, y1)*(x1 - 1) + b3.query(x1 - 1, y1)*y1;
				int c2 = b0.query(x1, y1 - 1) + b1.query(x1, y1 - 1)*x1*(y1 - 1) +
						 b2.query(x1, y1 - 1)*x1 + b3.query(x1, y1 - 1)*(y1 - 1);
				int c3 = b0.query(x1 - 1, y1 - 1) + b1.query(x1 - 1, y1 - 1)*(x1 - 1)*(y1 - 1) +
						 b2.query(x1 - 1, y1 - 1)*(x1 - 1) + b3.query(x1 - 1, y1 - 1)*(y1 - 1);

				cout << ((c0 + c3 - c1 - c2) & 1) << endl;
			}
		}
	}

};


int main(int argc, char** argv)
{
	Matrix a;

	a.solve(2, {'C', 'Q', 'C', 'Q', 'C', 'C', 'C', 'Q', 'C', 'Q'}, {2, 2, 2, 1, 1, 1, 1, 1, 1, 2},
				{1, 2, 1, 1, 1, 2, 1, 1, 1, 1}, {2, 0, 2, 0, 2, 1, 2, 0, 2, 0}, {2, 0, 1, 0, 1, 2, 2, 0, 1, 0});

	return 0;
}
