#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll F[1000007], P[1000007];

void preprocess()
{
    F[3] = 0; P[3] = 0;
    ll x = 0;
    for(int i=4; i<=1000000; ++i)
    {
        if(i % 2 == 0)
        {
            ++x;
            P[i] = P[i-1] + x;
            F[i] = F[i-1] + P[i];
        }
        else
        {
            P[i] = P[i-1] + x;
            F[i] = F[i-1] + P[i];
        }
    }
}

int main()
{
    preprocess();
    int n;
    while(cin >> n && n >= 3)
    {
        cout << F[n] << endl;
    }
}