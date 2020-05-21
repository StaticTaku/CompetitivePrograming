#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int i, j, k;

int N, A, B, C;
int x, y, z,rangeMax,flag;

void solve()
{
	cin >> N;
	REP(i, N)
	{
		cin >> A >> B >> C;
		flag = 0;
		rangeMax = sqrt(C);
		FOR(x, -rangeMax, rangeMax+1)
		{
			FOR(y, x+1, rangeMax+1)
			{
				FOR(z, y+1, rangeMax+1)
				{
					if (x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
					{
						flag = 1;
						break;
					}
				}

				if (flag)
					break;
			}

			if (flag)
				break;
		}

		if (flag)
			printf("%d %d %d\n", x, y, z);
		else
			cout << "No solution.\n";
	}
}

int main()
{
	solve();
}