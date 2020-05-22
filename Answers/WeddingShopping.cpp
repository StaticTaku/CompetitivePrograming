#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int i, j, k;

int N, M, C;
int K[20],Value[20][20];
int dp[20][201];

int maxShopFrom(int p,int m,int dp[][201])
{
	if (m > M)
		return -1;
	if (p == C)
		return m;

	if (dp[p][m] != -2)
		return dp[p][m];

	int ma = -1;
	int a;
	REP(a, K[p])
		ma = max(ma,maxShopFrom(p+1,m+Value[p][a],dp));
	
	dp[p][m] = ma;
	return ma;
}
int main()
{
	cin >> N;
	REP(i, N)
	{
		cin >> M >> C;

		REP(j, C)
		{
			cin >> K[j];
			REP(k, K[j])
				cin >> Value[j][k];
		}

		REP(j, C)
			REP(k, M + 1)
			dp[j][k] = -2;
		
		int a = maxShopFrom(0, 0, dp);
		if (a == -1)
			cout << "no solution\n";
		else
			cout << a << "\n";

	}
}