#include <bits/stdc++.h>

using namespace std;

int kmpPreprocess(string& str)
{
    int i = 0, j = -1;
    vector<int> b(str.length()+1);
    b[0] = -1;
    while(i < str.length())
    {
        while(j >= 0 && str[i] != str[j])
        {
            j = b[j];
        }
        i++; j++;
        b[i] = j;
    }
    return j;
}

int main()
{
    string str;
    while(getline(cin,str),str != ".")
    {
        int len = kmpPreprocess(str);
        int min = str.length() - len;
        if(str.length() % min)
        {
            printf("1\n");
        } else
            printf("%d\n",str.length()/min);
    }
}