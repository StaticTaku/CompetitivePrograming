#include <iostream>
#include <cstdio>
#include <algorithm>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int i, j, k,m;
int n, l;
int ansCount;
int board[8][8];
int c[64];
int r[64];

bool valid(int x, int y, int a)
{
	if (board[x][y] < 0)
		return false;
	if (board[x][y] < a)
		return false;
	REP(m, a)
	{
		if (abs(c[m] - x) == abs(r[m] - y))
			return false;
	}

	return true;
}
void place(int a)
{
	if (a == l)
	{
		++ansCount;
		return;
	}
	int x, y;
	REP(x, n)
	{
		REP(y, n)
		{
			if (valid(x, y, a))
			{
				board[x][y] = -100;
				r[a] = y;
				c[a] = x;
				place(a + 1);
				board[x][y] = a;
			}

		}
	}
}
void solve()
{
	while (true)
	{
		cin >> n >> l;
		if (n == 0 && l == 0)
			return;

		if (n * n < l)
		{
			cout << 0 << '\n';
			return;
		}

		REP(i, n)
			REP(j, n)
			board[i][j] = 100;

		ansCount = 0;

		place(0);

		cout << ansCount << "\n";
	}


}

int main()
{
	solve();
}