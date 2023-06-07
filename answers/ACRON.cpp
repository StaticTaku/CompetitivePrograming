#include <bits/stdc++.h>
using namespace std;

int dp[2004];
int Nuts[2004][2004];

int main()
{
    int k,t,h,f;
    int a,b,c;

    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d %d",&t,&h,&f);
        fill(&Nuts[0][0],&Nuts[h+2][t+2],0);
        fill(&dp[0],&dp[h+2],0);
        for(int i=1; i<=t; ++i)
        {
            scanf("%d",&a);
            for (int j=1; j<=a; j++)
            {
                scanf("%d",&c);
                Nuts[c][i]++;
            }
        }
 
 
        for (int i=0; i<=h; ++i)
        {
            for (int j=1; j<=t; ++j)
            {
 
                b = 0;
                if(i-f >= 0)
                    b=dp[i-f];
                c = 0;
                if(i-1 >= 0)
                    c = Nuts[i-1][j];

                Nuts[i][j] += max(b,c);
                dp[i] = max(dp[i],Nuts[i][j]);
 
            }
         
        }
        printf("%d\n",dp[h]);
    }
    scanf("%d",&a);
 
    return 0;
}