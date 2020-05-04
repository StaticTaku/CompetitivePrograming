#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int i, j, t, n, speed,_max;

void Solve()
{
	cin.tie(0); ios_base::sync_with_stdio(false);

	cin >> t;
	FOR(i, 1, t+1)
	{
		_max = 0;
		cin >> n;
		REP(j, n)
		{
			cin >> speed;
			_max = max(_max, speed);
		}

		cout << "Case " << i << ": " << _max << '\n';
	}
}

int main()
{
	Solve();
}