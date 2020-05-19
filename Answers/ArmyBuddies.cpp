#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define SIZE (int)1e5

#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define REP(i,a)   for(i = 0;i < (a);++i)

int R[SIZE+1], L[SIZE+1];
int a, b,c,d,i,j;

void solve()
{
	while (true)
	{
       cin >> a >> b;
	   if (a == 0 && b == 0)
	   {
		   return;
	   }

	   R[a] = -1; L[1] = -1;

	   if (a != 1)
	   {
		   FOR(i, 1, a)
		   {
			   R[i] = i + 1;
			   L[i + 1] = i;
		   }
	   }

	   while (b > 0)
	   {
		   cin >> i >> j;
		   if (i > j)
		   {
			   int k = i;
			   i = j;
			   j = k;
		   }
		   if (L[i] != -1)
		   {
			   c = L[i]; R[c] = R[j];
		   }
		   else
		   {
			   c = -5;
		   }

		   if (R[j] != -1)
		   {
			   d = R[j]; L[d] = L[i];
		   }
		   else
		   {
			   d = -5;
		   }

		   if (c == -5)
		   {
			   cout << "* ";
		   }
		   else
		   {
			   cout << c << ' ';
		   }

		   if (d == -5)
		   {
			   cout << "*" << '\n';
		   }
		   else
		   {
			   cout << d << '\n';
		   }

		   --b;

		   
	   }

	   cout << "-" << "\n";
	}

}

int main()
{
	solve();
}