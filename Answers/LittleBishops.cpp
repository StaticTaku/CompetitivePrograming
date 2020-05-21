#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
#define N 9
#define M 15
typedef long long LL;

int main()
{
    LL black[9][15] = {}, white[9][15] = {};
    int rowBlack[9] = { 0, 1, 1 };    
    int rowWhite[9] = { 0, 0, 2, 2 };
    int i, j;

    for (int i = 3; i < N; i += 2) 
        rowBlack[i] = rowBlack[i + 1] = rowBlack[i - 1] + 2;
    for (int i = 4; i <= 6; i += 2)
        rowWhite[i] = rowWhite[i + 1] = rowWhite[i - 1] + 2;


    rowWhite[8] = rowWhite[7] + 2;

    REP(i,N)
       black[i][0] = 1;

    REP(i,N)
        white[i][0] = 1;

    FOR(i,1,N)
        for (int k = 1; k < M; ++k)
            black[i][k] = black[i - 1][k] + black[i - 1][k - 1] * (rowBlack[i] - (k - 1));

    FOR(i,2,N)
        for (int k = 1; k < M; ++k)
            white[i][k] = white[i - 1][k] + white[i - 1][k - 1] * (rowWhite[i] - (k - 1));

    int n, k;
    while (true)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
            return 0;

        if (k >= M)
        {
            cout << 0 << "\n";
            continue;
        }

        LL sum = 0;
        REP(i,k+1)
            sum += (black[n][i] * white[n][k - i]);

        printf("%lld\n", sum);
    }

    return 0;
}