#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

char matrix[26][26];
int t,n;

char ctoi(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	}
}
int main()
{
	cin >> t;
	int i,j,k,aa;
	aa = 1;
	REP(j, t)
	{
		if (aa != 1) {
			cout << "\n";
		}

		++aa;
		int n = 0;
		cin >> matrix[0];
		for (i = 0; matrix[0][i] != '\0'; ++i)
			++n;

		FOR(i, 1, n)
			cin >> matrix[i];

		REP(i, n)
			REP(k, n)
			matrix[i][k] = ctoi(matrix[i][k]);
		int ST[26][26];

		REP(i, n)
		{
			REP(k, n)
			{
				ST[i][k] = matrix[i][k];
				if (i > 0)
					ST[i][k] += ST[i - 1][k];
				if (k > 0)
					ST[i][k] += ST[i][k - 1];

				if (i > 0 && k > 0)
					ST[i][k] -= ST[i - 1][k - 1];
			}
		}

		int x, y, sum;
		int ans = 0;
		REP(i, n)
		{
			REP(k, n)
			{
				FOR(x,i,n)
				{
					FOR(y,k, n)
					{
						sum = ST[x][y];
						if (i > 0)
							sum -= ST[i - 1][y];
						if (k > 0)
							sum -= ST[x][k - 1];

						if (i > 0 && k > 0)
							sum += ST[i - 1][k - 1];

						if (sum == (x - i + 1) * (y - k + 1))
							ans = max(ans, (x-i + 1)*(y-k + 1));
					}
				}
			}
		}

		cout << ans << "\n";
		
	}
}