#ifndef MATRIX_H
#define MATRIX_H


#include <vector>


typedef std::vector<int> VI;
typedef std::vector<VI> mat;

typedef long long ll;


mat mul(mat A, mat B, int M)
{
	mat C(A.size(), VI(B[0].size(), 0));
	
	for (int i = 0; i != A.size(); ++i)
	{
		for (int j = 0; j != B[0].size(); ++j)
		{
			for (int k = 0; k != B.size(); ++k)
			{
				C[i][j] += (A[i][k] * B[k][j]) % M;
				
				C[i][j] %= M;
			}
		}
	}
	
	return move(C);
}

mat pow(mat A, ll n, int M)
{
	mat B(A.size(), VI(A[0].size(), 0));
	
	for (int i = 0; i != A.size(); ++i)
	{
		B[i][i] = 1;
	}
	
	while (n > 0)
	{
		if (n & 1) B = mul(B, A, M);
		
		A = mul(A, A, M);
		
		n >>= 1;
	}
	
	return B;
}


#endif	// MATRIX_H
