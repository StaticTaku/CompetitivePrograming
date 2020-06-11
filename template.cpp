#include <bits/stdc++.h>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

typedef pair<int,int> edge;
typedef vector<edge> neighb;
vector<neighb> AdjList;

/*#define N 1000
int visited[N];

void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0;i<AdjList[v].size();++i)
    {
        edge u = AdjList[v][i];
        //do_something
        if(visited[u.first] == 0)
            dfs(u.first);
    }
}
*/

/*int visited[100];
queue<int> que;

void bfs(int v)
{
    while(!que.empty())
    {
        int u = que.front(); que.pop();
        visited[u] = 1;
        //do_something
        for(int i = 0;i<AdjList[v].size();++i)
        {
            edge e = AdjList[u][i];
            if(visited[e.first] == 0)
                que.push(e.first);
        }
    }
}
*/

int main()
{
    int t;
    cin >> t;
    int nodesNum,_edge;

    /*for(int i = 0;i<t;++i)
    {
        cin >> nodesNum;
        AdjList.resize(0);
        for(int j = 0;j<nodesNum;++j)
        {
            AdjList.emplace_back();
            for(int k = 0;k<nodesNum;++k)
            {
                cin >> _edge;
                if(_edge == 1)
                    AdjList[j].emplace_back(k,1);
            }
        }
    }*/

}