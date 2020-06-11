#include <bits/stdc++.h>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

typedef pair<int,int> edge;
typedef vector<edge> neighb;
vector<neighb> AdjList;

int dominated[100][100];
int visited[100];

void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0;i<AdjList[v].size();++i)
    {
        edge u = AdjList[v][i];
        if(visited[u.first] == 0)
            dfs(u.first);
    }
}
int main()
{
    int t;
    cin >> t;
    int nodesNum,_edge;

    for(int i = 0;i<t;++i)
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

        for(int j = 0;j<nodesNum;++j)
        {
            for(int k = 0;k<nodesNum;++k)
            {
                dominated[j][k] = 0;
            }

            visited[j] = 0;
        }

        dfs(0);

        for(int j = 0;j<nodesNum;++j)
        {
            if(visited[j])
                dominated[0][j] = 1;
        }

        for(int j = 1;j<nodesNum;++j)
        {
            fill(visited,visited+nodesNum,0);
            visited[j] = 1;
            if(dominated[0][j])
                dominated[j][j] = 1;
            dfs(0);
            for(int k = 0;k<nodesNum;++k)
            {
                if(!visited[k] && dominated[0][k])
                    dominated[j][k] = 1;
            }


        }

        cout << "Case " << i+1 <<":" << "\n";
        for(int k = 0;k<nodesNum;++k)
        {
            cout << "+";
            for(int j = 1;j<2*nodesNum;++j)
            {
                cout << "-";
            }
            cout << "+" << "\n";

            cout << "|";
            for(int j = 0;j<nodesNum;++j)
            {
                if(dominated[k][j])
                    cout << "Y" << "|";
                else 
                    cout << "N" << "|";
            }

            cout << "\n";
        }

        cout << "+";
            for(int j = 1;j<2*nodesNum;++j)
            {
                cout << "-";
            }
            cout << "+" << "\n";
    }
}