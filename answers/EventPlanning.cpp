#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 1000000
using namespace std;

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int i, j, a, b, c, d, p,bed, beds[13], minimum;
void Solve()
{
	
	bool find;
	int _sum;
	while (cin >> a >> b >> c >> d)
	{
		minimum = INF;
		_sum = 0;
		REP(i, c)
		{
			cin >> p;
			find = false;
			REP(j, d)
			{
				cin >> beds[j];
			}

			REP(j, d)
			{
				if (beds[j] < a)
				{
					continue;
				}
				else
				{

					find = true;
					continue;
				}
					
			}

			if (!find)
				continue;

			_sum = a * p;
			if (b < _sum)
				continue;

			minimum = min(minimum, _sum);
		}

		if (minimum == INF)
			cout << "stay home" << '\n';
		else
			cout << minimum << '\n';
	}

}

int main()
{
	Solve();
}