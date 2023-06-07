#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50
#define INF 1<<29

int L, N;
int cut[MAX_N+2];
bool visited[MAX_N+2][MAX_N+2];
int dp[MAX_N+2][MAX_N+2];

int solve(int a, int b)
{
	if(visited[a][b])
    {
		return dp[a][b];
	}
	visited[a][b] = true;

	int& ret = dp[a][b];
	ret = INF;
    
	if(b - a == 1)
    {
		return ret = 0;
	}

	for(int c=a+1; c < b; ++c)
    {
		ret = min(ret, cut[b] - cut[a] + solve(a, c) + solve(c, b));
	}
	return ret;
}

int main()
{
	while(scanf("%d", &L), L)
    {
		scanf("%d", &N);

	    for(int i=0; i<N; i++)
        {
	    	scanf("%d", cut+i+1);
	    }
	    cut[N+1] = L;

	memset(visited, false, sizeof(visited));
		printf("The minimum cutting is %d.\n", solve(0,N+1));
	}

	return 0;
}