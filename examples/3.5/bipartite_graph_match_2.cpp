/**
  * @file bipartite graph match 
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
#include <memory.h>

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


const int MAX_V = 1000;

int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];


bool dfs(int v)
{
	used[v] = true;
	
	for (auto u : G[v])
	{
		int w = match[u];
		
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	
	return false;
}

int bipartite_matching()
{
	int ans = 0;
	
	memset(match, -1, sizeof(match));
	
	for (int i = 0; i != V; ++i)
	{
		memset(used, 0, sizeof(used));
		
		if (dfs(i)) ++ ans;
	}
	
	return ans;
}


int main(int argc, char** argv)
{
	return 0;
}

/*

for convenient

*/

