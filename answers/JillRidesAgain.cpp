#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int b, s;
int value[20001];
int save[2][2];

int main()
{
	int i; int j;
	cin >> b;
	REP(i, b)
	{
		cin >> s;
		FOR(j,1,s)
		{
			cin >> value[j];
		}

		int sum = 0; int ans[2] = { 0 };
		save[0][0] = 1;
		FOR(j,1,s)
		{
			sum += value[j];
			if (sum >= ans[0])
			{
				ans[0] = sum;
				save[0][1] = j;
			}

			if (sum < 0)
			{
				sum = 0;
				if ((ans[0] > ans[1]) || ((ans[0] == ans[1]) && (save[0][1] - save[0][0]) > (save[1][1] - save[1][0])))
				{
					save[1][0] = save[0][0];
					save[1][1] = save[0][1];
					ans[1] = ans[0];
					ans[0] = 0;
				}
				save[0][0] = j + 1;
			}
		}

		if ((ans[0] > ans[1]) || ((ans[0] == ans[1]) && (save[0][1] - save[0][0]) > (save[1][1] - save[1][0])))
		{
			save[1][0] = save[0][0];
			save[1][1] = save[0][1];
			ans[1] = ans[0];
			ans[0] = 0;
		}

		if (ans[1] > 0)
		{
			printf("The nicest part of route %d is between stops %d and %d\n", i+1, save[1][0], save[1][1] + 1);
		}
		else
		{
			printf("Route %d has no nice parts\n",i+1);
		}
	}
}