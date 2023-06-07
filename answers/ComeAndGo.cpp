#include <bits/stdc++.h>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

vector<vector<int> > adjList;
vector<int> dfs_low;
vector<int> dfs_num;


int scc;
int counter;

void findSCC(int u)
{
	dfs_low[u] = counter;
	dfs_num[u] = counter++;
	int size = adjList[u].size();

	for(int i = 0; i < size; ++i)
	{
		int v = adjList[u][i];
		
		if(dfs_num[v] == -1)
			findSCC(v);
		
		if(dfs_num[v] != -1)
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_num[u] == dfs_low[u])
		++scc;
}

int main(void)
{
    
	int m,n;
	while(true)
	{
        cin >> n >> m;
        if(n == 0 && m == 0)
            return 0;
        
		adjList.assign(n + 1, vector<int>());

		for(int i = 0; i < m; ++i)
		{
			int a,b,ways;
			cin >> a >> b >> ways;

			adjList[a].push_back(b);
			if(ways == 2)
				adjList[b].push_back(a);
		}

		scc = 0;
		counter = 1;
		dfs_low.assign(n + 1,-1);
		dfs_num.assign(n + 1, -1);

		findSCC(1);

		for(int i = 2; i < n+1; ++i)
		{
			if(dfs_num[i] == -1)
			{
				scc = 0;break;
            }
		}
	
		if(scc == 1)
			cout << "1\n";
		else
			cout << "0\n";
	}

}