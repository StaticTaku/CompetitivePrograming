#include <bits/stdc++.h>
using namespace std;

#define MOVE 100

vector<int> N;vector<char> S; set<int> V;
bool dp[35][35][6005];

void search(int idx, int p, int value)
{
    if (idx == N.size())
    {
        V.insert(value);
        return;
    }
    else if (dp[idx][p][value + idx * MOVE])
        return;

    if (S[idx] == '-')
        search(idx + 1,p + 1,value + (p % 2 == 0? N[idx] : -N[idx]));

    for (int i = 0; i <= p; ++i)
        search(idx + 1,p - i,value + (p % 2 == 0? N[idx] : -N[idx])); 

    dp[idx][p][value + idx * MOVE] = true;
}

int solve()
{
    memset(dp, false, sizeof(dp));
    V.clear();
    search(0, 0, 0);
    return V.size(); 
}

int main()
{
    string s;
    while (getline(cin, s)) 
    {
        stringstream ss(s);
        char s;
        int num;

        ss >> num;
        N.clear(); S.clear();
        N.push_back(num); S.push_back('+');
        while (ss >> s >> num)
        {
            N.push_back(s == '+'? num : -num);
            S.push_back(s);
        }

        memset(dp, false, sizeof(dp));
        V.clear();
        search(0, 0, 0);
        
        cout << V.size() << endl;
    }
    return 0;
} 