#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int k,j,queens[8], brain[8];

bool valid(int r, int c) {
    REP(j,r)
    {
        if (c == brain[j]) 
            return false;
        if (abs(r - j) == abs(c - brain[j])) 
            return false;
    }

    return true;
}

int dfs(int n) {
    if (n == 8) return 0;

    int point = 100000;

    for (int i = 0; i < 8; i++)
    {
        if (valid(n, i)) {
            brain[n] = i;
            point = min(point, i == queens[n] ? dfs(n + 1) : 1 + dfs(n + 1));
        }
    }

    return point;
}
void solve()
{
    int T = 1;
    while (true)
    {
        REP(k, 8)
        {
            cin >> queens[k];
            brain[k] = --queens[k];
        }

        if (cin.fail())
            return;
        printf("Case %d: %d\n", T, dfs(0));
        ++T;
    }
}
int main() 
{
    solve();
}