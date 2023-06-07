#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() 
{
    int N, D;
    int n;
    while(scanf("%d %d", &N, &D) && (N || D)) 
    {
        int judge[105] = {};
        ll ans;
        for(int i = 2; i <= N; i++) 
        {
            n = i;
            for(int j = 2; j <= n; j++)
            {
                while(n%j == 0) 
                {
                    n /= j, judge[j]++;
                }
            }
        }
        int a = 0;
        for(int i = 2; i < 100 && !a; i++) 
        {
            while(D%i == 0) 
            {
                if(judge[i] == 0) 
                {
                    a = 1;
                    break;
                }
                judge[i]--;
                D /= i;
            }
        }
        if(D != 1 && (D > 100 || judge[D] == 0))
            a = 1;
        else if(D != 1)
            judge[D]--;
        
        if(a) 
        {
            puts("0");
            continue;
        }
        ans = 1;
        for(int i = 0; i <= N; i++) 
        {
            ans *= judge[i]+1;
        }
        cout << ans << endl;
    }
    return 0;
}