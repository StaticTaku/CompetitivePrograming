#include <bits/stdc++.h>
using namespace std;

int P = 131071;

int main()
{    
    string n;
    int v = 0;
    while (getline(cin, n))
    {
        for (size_t i = 0; i < n.length(); ++i)
        {
            if (n[i] == '#')
            {
                if(v == 0)
                {
                    cout << "YES" << endl;
                }else 
                {
                    cout << "NO" << endl;
                }
                v = 0;
            }
            else if (n[i] >= '0' && n[i] <= '9')
            {
                v = ((n[i] - '0') + (v << 1)) % P;
            }
        }
    }
    return 0;
}