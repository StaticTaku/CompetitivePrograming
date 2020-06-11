#include <bits/stdc++.h>

#define MAX 50001
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int dfs_vis[MAX],foward[MAX],memo[MAX];

int dfs(int u)
{
    int v = foward[u];
    int r = 0;
    dfs_vis[u] = 1;
    if(!dfs_vis[v])
        r = 1 + dfs(v);
    dfs_vis[u] = 0;
    memo[u] = r;
    return r;
}

int main()
{
    int T,u,v,N;
    cin >> T;
    for(int t = 0;t<T;++t)
    {
        cin >> N;
        for(int i = 0;i < N;++i)
        {
            cin >> u >> v;
            foward[u] = v;
        }

        for(int i = 1;i<=N;++i)
        {
            dfs_vis[i] = 0;
            memo[i] = -1;
        }

        int m = -1;
        int start;
        for(int i = 1;i<=N;++i)
        {
            if(memo[i] == -1) dfs(i);
            if(memo[i] > m)
            {
                m = memo[i];
                start = i;
            }
        }
        cout << "Case " << t+1 << ": " << start << "\n";
    }
}