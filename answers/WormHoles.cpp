#include <bits/stdc++.h>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)


int edge[2000][2];
int weight[2000];
int dist[1000];
bool reached[1000];


int main()
{    
    int T,n,m;
    
    bool found;
    
    cin >> T;
    
    for(int a = 0;a < T; ++a)
    {
        cin >> n >> m;
        
        for(int i = 0;i < m; ++i)
            cin >> edge[i][0] >> edge[i][1] >> weight[i];


        dist[0]=0;
        reached[0]=true;
        
        for(int i=1;i<n;i++) 
            reached[i]=false;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(reached[edge[j][0]])
                {
                    if(!reached[edge[j][1]])
                    {
                        dist[edge[j][1]]=dist[edge[j][0]]+weight[j];
                        reached[edge[j][1]]=true;
                    }else dist[edge[j][1]] = dist[edge[j][0]]+weight[j];
                }
            }
        }
        found=false;
        
        for(int j=0;j<m && !found;++j)
        {
            if(reached[edge[j][0]])
                if(!reached[edge[j][1]] || dist[edge[j][1]]>dist[edge[j][0]]+weight[j]) 
                    found=true;
        }
        if(found) 
            cout << "possible\n";
        else
            cout << "not possible\n";
        
    }
    
    return 0;
}