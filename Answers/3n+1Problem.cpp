#include <iostream>
#include <cstdio>
#include <algorithm>

#define SIZE 100000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);

	int i, j, k;
	int counter = 1;
	int maxNum = 0;
	int mem[SIZE] = {0};

	while (cin >> j >> k)
	{
		FOR(i, min(j, k), max(j, k) + 1)
		{
			int _i = i;
			while (_i != 1)
			{
				_i = _i % 2 == 0 ? _i / 2 : 3 * _i + 1;
				if (_i < SIZE && mem[_i] > 0)
				{
					counter += mem[_i];
					break;
				}
				++counter;
			}



			if (i < SIZE && mem[i] <= 0)
				mem[i] = counter;

			maxNum = max(maxNum, counter);

			counter = 1;
		}

		cout << j << ' ' << k << ' ' << maxNum << '\n';

		maxNum = 0;
	}
}