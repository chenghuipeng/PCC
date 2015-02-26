#ifndef DBIT_H
#define DBIT_H


/** @file
  * @brief
  * @author malin
  * @date 2014年08月05日 星期二 14时59分53秒
  * @version 1.0
  */


#include <vector>
#include <iostream>


class DBIT
{
public:
	DBIT(int h, int w) : array(h + 1, std::vector<int>(w + 1, 0)), W(w), H(h) {}

	void update(int x, int y, int v)
	{
		while (y <= H)
		{
			int xx = x;
			while (xx <= W)
			{
				array[y][xx] += v;

				xx += xx & (-xx);
			}

			y += y & (-y);
		}
	}

	int query(int x, int y)
	{
		int ans = 0;

		while (y > 0)
		{
			int xx = x;
			while (xx > 0)
			{
				ans += array[y][xx];

				xx -= xx & (-xx);
			}

			y -= y & (-y);
		}

		return ans;
	}

	void print()
	{
		for (auto& v : array)
		{
			for (auto x : v) std::cout << x << ' ';
			
			std::cout << std::endl;
		}
	}

private:
	std::vector<std::vector<int> > array;
	int W, H;

};


#endif	// DBIT_H
