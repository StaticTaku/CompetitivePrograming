#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int mx=0;
string ans;
set<string> dict;

void check(const string &s)
{
    string t;
    int i = 0, tx = 0;
    while(i<s.size())
    {
        if(s[i]==' ')
        {
            if(dict.find(t)!=dict.end())
                tx++;
            t="";
        }
        else
            t+=s[i];
        ++i;
    }
    if(tx > mx)
        mx = tx,ans = s;
}
int main()
{
    string s;
    while(cin >> s && s[0] != '#')
    {
        dict.insert(s);
    }
    ws(cin);
    getline(cin,s);
    for(int j = 0;j <= 27;++j)
    {
        for(int i = 0;i < s.size();++i)
        {
            if(s[i]==' ')
                s[i]='A';
            else if(s[i]=='Z')
                s[i]=' ';
            else
                s[i] = 1 + int(s[i]);
        }
        check(s);
    }
    string a,b;
    stringstream ss(ans);
    while(ss >> b)
    {
        if(a.size()+b.size()>60)
        {
            cout << a << endl;
            a=b;
        }
        else
        {
            if(a.size()!=0)
                a+=' ';
            a+=b;
        }
    }
    cout<<a<<endl;

    return 0;
}