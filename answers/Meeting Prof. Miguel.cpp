#include <bits/stdc++.h>
#define inf 1<<29
#define SIZE 28

using namespace std;
int n;

struct dt
{
    int n,d;
    dt(int a,int b):n(a),d(b){}
};

int comp(dt a,dt b)
{
    if(a.d==b.d)
        return a.n < b.n;
    else return a.d < b.d;
}
void init(int dist[][SIZE])
{
    int i,j;

    for(i=1; i<SIZE; ++i)
    {
        for(j=1; j<SIZE; ++j)
        {
            dist[i][j]=inf;
            if(i==j)
                dist[i][j]=0;
        }
    }
}
void warshallFloyd(int dist[][SIZE])
{
    int i,j,k;
    for(k=1; k<SIZE; ++k)
        for(i=1; i<SIZE; ++i)
            for(j=1; j<SIZE; ++j)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];


}

vector<dt> ans;
int main()
{
    int i,j,w;
    int Adj1[SIZE][SIZE],Adj2[SIZE][SIZE];
    char a,d,x,y;

    while(true)
    {
        cin>>n;
        if(n==0)
            return 0;
            
        init(Adj1);
        init(Adj2);
        ans.clear();
        for(i=1; i<=n; ++i)
        {
            cin >> a >> d >> x >> y >> w;

            if(a=='Y')
            {
                if(Adj1[x-64][y-64] > w)
                    Adj1[x-64][y-64] = w;
                if(d=='B')
                {
                    if(Adj1[y-64][x-64] > w)
                        Adj1[y-64][x-64] = w;
                }
            }
            else
            {
                if(Adj2[x-64][y-64]>w)
                    Adj2[x-64][y-64]=w;
                if(d=='B'){
                if(Adj2[y-64][x-64]>w)
                    Adj2[y-64][x-64]=w;
                }
            }

        }
        cin >> x >> y;

        warshallFloyd(Adj1);
        warshallFloyd(Adj2);

        for(i=1; i<SIZE; i++)
        {
            int d1=Adj1[x-64][i];
            int d2=Adj2[y-64][i];
            if(d1!=inf && d2!=inf)
                ans.push_back(dt(i,d1+d2));
        }
        if(ans.size()==0)
        {
            printf("You will never meet.\n");
            continue;
        }

        sort(ans.begin(),ans.end(),comp);
        for(i=0; i<ans.size(); i++)
        {
            if(i==0)
                printf("%d",ans[i].d);
           if(ans[i].d==ans[0].d)
                printf(" %c",ans[i].n+64);
        }
        printf("\n");
   }
    return 0;
}