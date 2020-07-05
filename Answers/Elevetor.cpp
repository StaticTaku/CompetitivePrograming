#include <bits/stdc++.h>
using namespace std;

bool comp(int l, int w, int r1, int r2)
{
    int low = l < w ? l : w;
    
    if (r1 * 2 > low || r2 * 2 > low)
        return false;
    
    int x = l - r1 - r2, y = w - r1 - r2, r = r1 + r2;
    
    if (r * r <= x * x + y * y)
    {
        return true;
    }
    
    return false;
}

int main()
{
    int l, w, r1, r2;
    
    while (scanf("%d %d %d %d", &l, &w, &r1, &r2) && l)
    {
        if (comp(l, w, r1, r2))
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
}