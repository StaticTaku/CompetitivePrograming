#include <bits/stdc++.h>
#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

typedef pair<int,int> edge;
typedef vector<edge> neighb;

int main()
{  
    int T;
    cin >> T;
    for(int t = 0;t<T;++t)
    {
        int v, e;
        cin >> v >> e;
        
        vector<vector<int> > adjList(v);
        vector<int> color(v, 2);
        bool isBipartite = true;
        
        for(int i = 0;i<e;++i)
        {
            int junk1, junk2;
            cin >> junk1 >> junk2;
            adjList[junk1].push_back(junk2);
            adjList[junk2].push_back(junk1);
        }

        int counter = 0;
        for (int j = 0; j < adjList.size() && isBipartite; ++j)
        {
            if (color[j] != 2)
                continue;

            queue<int> q; q.push(j);
            int count[2] = {0};
            color[j] = 0;
            ++count[color[j]];

            while (!q.empty() && isBipartite)
            {
                int u = q.front();
                q.pop();
                for (int i = 0; i < adjList[u].size(); ++i)
                {
                    int v = adjList[u][i];
                    if (color[v] == color[u])
                    {
                        isBipartite = false;
                        break;
                    }
                    else if (color[v] == 2)
                    {
                        color[v] = 1 - color[u]; 
                        ++count[color[v]];
                        q.push(v);
                    }
                }
            }
            counter += max(1, min(count[0], count[1]));
        }

        if (isBipartite)
            cout << counter << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}