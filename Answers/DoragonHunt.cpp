#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int n, m,i,j;
int knights[20000],heads[20000];


void solve()
{
	string fail = "Loowater is doomed!";
	int counter = 0;
	bool kill = false;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			return;

		if (n > m)
		{
			cout << fail << "\n";
			REP(i, n)
				cin >> heads[i];
			REP(i, m)
				cin >> knights[i];
			continue;
		}

		REP(i, n)
			cin >> heads[i];
		REP(i, m)
			cin >> knights[i];

		sort(knights, knights + m); sort(heads, heads + n);

		j = 0; counter = 0; kill = false;
		REP(i, n)
		{
			while (true)
			{
				if (j == m)
					break;

				if (heads[i] <= knights[j])
				{
					counter += knights[j++];
					if (i == n - 1)
						kill = true;
					break;
				}

				++j;
			}

			if (j == m)
			{
				break;
			}

		}

		if (kill)
			cout << counter << "\n";
		else
			cout << "Loowater is doomed!" << "\n";
	}
}
int main()
{
	solve();
}