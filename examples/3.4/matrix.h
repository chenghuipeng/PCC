/** @file
  * @brief Matrix
  * @author malin
  * @date 2014年08月08日 星期五 16时22分03秒
  * @version 1.0
  */


#include <vector>


typedef long long ll;
typedef std::vector<std::vector<int> > mat;


mat mul(mat A, mat B, int M)
	{
		mat C(A.size(), std::vector<int>(B[0].size(), 0));

		for (int i = 0; i != A.size(); ++i)
		{
			for (int j = 0; j != B[0].size(); ++j)
			{
				for (int k = 0; k != B.size(); ++k)
				{
					C[i][j] += (A[i][k] * B[k][j]) % M;
				}
			}
		}

		return C;
	}

	mat pow(mat A, ll n, int M)
	{
		mat B(A.size(), std::vector<int>(A[0].size(), 0));

		for (int i = 0; i != A.size(); ++i) B[i][i] = 1;

		while (n > 0)
		{
			if (n & 1) B = mul(B, A, M);

			A = mul(A, A, M);

			n >>= 1;
		}

		return B;
	}
