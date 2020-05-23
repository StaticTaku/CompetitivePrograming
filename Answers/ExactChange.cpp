#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int sum, n,i,j;
        int money, index;
        cin >> sum >> n;

        vector<int> coin(n + 1);
        FOR(i,1,n+1)
            cin >> coin[i];

        vector<vector<int> > d(102, vector<int>(20001, 10001));

        REP(i,n)
            d[i][0] = 0;

        FOR(i,1,n+1) 
        {
            FOR(j,1,20001) 
            {
                if (coin[i] <= j)
                    d[i][j] = min(d[i - 1][j], 1 + d[i - 1][j - coin[i]]);
                else
                    d[i][j] = d[i - 1][j];
            }
        }
        FOR(i,sum,20001) 
        {
            index = d[n][i];
            money = i;
            if (index != 10001)
                break;
        }
        cout << money << ' ' << index << "\n";

    }
}