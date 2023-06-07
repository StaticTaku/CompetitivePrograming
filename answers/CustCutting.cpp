#include <iostream>
#include <cstdio>
#include <algorithm>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int T, i,s[3];

void Solve()
{
	FOR(i, 1, T + 1)
	{
		cin >> s[0] >> s[1] >> s[2];
		sort(s, s + 3);
		cout << "Case " << i << ": " << s[1] << '\n';
	}
}

int main()
{
	cin >> T;
	Solve();
}