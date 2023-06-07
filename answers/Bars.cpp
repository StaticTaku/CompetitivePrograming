#include <iostream>
#include <cstdio>
#include <algorithm>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int i, j, k;


int t, n, p, a[20], dp[1001][20] = {0};

void solve()
{
	REP(i, 20)
	{
		dp[0][i] = 1;
	}
	cin >> t;
	REP(i, t)
	{
		cin >> n >> p;
		REP(j, p)
			cin >> a[j];

		dp[a[0]][0] = 1;

		FOR(j,1, n + 1)
		{
			FOR(k,1,p)
			{
				if (dp[j][k - 1] || (j - a[k] >= 0 && dp[j - a[k]][k - 1]))
					dp[j][k] = 1;
				else
					dp[j][k] = 0;

 			}
		}

		if (dp[n][p - 1])
			cout << "YES\n";
		else
			cout << "NO\n";

		dp[a[0]][0] = 0;
	}
}

int main()
{
	solve();
}