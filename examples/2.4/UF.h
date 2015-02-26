/** @file
  * @brief The definition of union-find.
  * @author ml
  * @date 09/07/14 15:28
  * @version 1.0
  */

#ifndef UF_H
#define UF_H

#include <vector>
#include <map>
#include <initializer_list>

template<typename T>
class UF
{
public:
	UF(std::initializer_list<T> p)
	{
		init(p);
	}
	
	void init(std::initializer_list<T> p)
	{
		int n = 0;
		for (auto itr = p.begin(); itr != p.end(); ++itr)
		{
			t.insert(*itr, n++);
		}
		
		par.resize(n); rank.resize(n);
		
		for (int i = 0; i != n; ++i)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}
	
	T find(T x)
	{
		if (par[t[x]] == t[x])
		{
			return x;
		}
		else
		{
			auto& p = find(par[t[x]]);
			par[t[x]] = t[p];
			
			return p;
		}
	}
	
	void unite(T x, T y)
	{
		x = find(x);
		y = find(y);
		
		if (x == y) return;
		
		if (rank[t[x]] < rank[t[y]])
		{
			par[t[x]] = t[y];
		}
		else
		{
			par[t[y]] = t[x];
			
			if (rank[t[x]] == rank[t[y]]) ++ rank[t[x]];
		}
	}
	
	bool same(T x, T y)
	{
		return find(x) == find(y);
	}

private:
	std::map<T, int> t;
	std::vector<int> par, rank;

};

template<>
class UF<int>
{
public:
	UF(int n = 0)
	{
		init(n);
	}
	
	void init(int n)
	{
		par.resize(n); rank.resize(n);
		
		for (int i = 0; i != n; ++i)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}
	
	int find(int x)
	{
		if (par[x] == x)
		{
			return x;
		}
		else
		{
			return par[x] = find(par[x]);
		}
	}
	
	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		
		if (x == y) return;
		
		if (rank[x] < rank[y])
		{
			par[x] = y;
		}
		else
		{
			par[y] = x;
			if (rank[x] == rank[y]) ++ rank[x];
		}
	}
	
	bool same(int x, int y)
	{
		return find(x) ==find(y);
	}
	
private:
	std::vector<int> par, rank;
	
};

#endif // UF_H

