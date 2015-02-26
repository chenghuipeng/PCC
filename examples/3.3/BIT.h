#ifndef BIT_H
#define BIT_H

/** @file
  * @brief BIT
  * @author malin
  * @date 2014年08月03日 星期日 15时30分47秒
  * @version 1.0
  */


#include <vector>
#include <iostream>


class BIT
{
public:
	BIT(int n_ = 0) : n(n_), array(n_ + 1, 0) {}

	void update(int i, int v)
	{
		while (i <= n)
		{
			array[i] += v;
			i += (i & (-i));
		}
	}
	
	void init(int n_)
	{
		n = n_;
		
		array.assign(n + 1, 0);
	}

	int sum(int i)
	{
		int s = 0;

		while ( i > 0)
		{
			s += array[i];
			i &= (i - 1);
		}

		return s;
	}
	
	void print()
	{
		for (auto x : array) std::cout << x << ' '; std::cout << std::endl;
	}

private:
	int n;					// The size of BIT
	std::vector<int> array; // The valid interval is [1..n]

};

#endif	// BIT_H
