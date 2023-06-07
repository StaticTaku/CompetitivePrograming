#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define INF 1000000000
using namespace std;

int p, r, bh, of, yh, m;
int p1, p2, d;
int boss[105][105], me[105][105];
int barria[105];


void warshallFloyd(int path[105][105])
{
	for(int k = 1;k <= p;++k)
    {
        if(barria[k]) continue;
		for(int i = 1;i <= p; ++i)
        {
			if(barria[i]) continue;
			for(int j=1;j <= p;++j)
            {
				if(barria[j]) continue;
				path[i][j] = min( path[i][k] + path[k][j], path[i][j] );
			}
		}
	}
}

int main()
{
	while(cin >> p >> r >> bh >> of >> yh >> m)
    {
		for(int i = 1;i <= p;++i)
        {
			for(int j = 1;j <= p;++j)
            {
				boss[i][j] = me[i][j] = INF;
			}
			boss[i][i] = me[i][i] = 0;
		}

		for(int i = 0;i < r;++i)
        {
			cin >> p1 >> p2 >> d;
			boss[p1][p2] = boss[p2][p1] = me[p1][p2] = me[p2][p1] = d;
		}

		memset(barria, 0, sizeof barria);
		warshallFloyd(boss);
		for(int i = 1;i <= p;++i)
        {
			if(boss[bh][of] == boss[bh][i] + boss[i][of]) 
                barria[i] = true;
		}
		if( barria[yh] || barria[m])
        {
			cout << "MISSION IMPOSSIBLE.\n";
			continue;
		}
		warshallFloyd(me);

		int ans = me[yh][m];
		if(ans == INF)
        {
			cout << "MISSION IMPOSSIBLE.\n";
		}
		else{
			cout << ans << endl;
		}
	}
    return 0;
}