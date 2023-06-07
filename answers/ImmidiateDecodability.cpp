#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b)
{
	if(a.size()<b.size())	swap(a,b);
	return(a.substr(0,b.size()) == b);
}

int main()
{
	vector<string> StrList;
	string s;
    int t = 0;
    bool a = false;

	while(cin >> s)
    {

		if(s!="9")
			StrList.push_back(s);
			
		while(cin >> s and s != "9")
			StrList.push_back(s);

		cout<<"Set "<<++t<<" is ";

		for(int i = 0; i < StrList.size(); ++i)
			for(int j = 0; j < StrList.size(); ++j)
            {
				if(i == j) continue;

				if(check(StrList[i],StrList[j]))
                {
					a = true;
				}
			}
        if(a)
			cout<<"not immediately decodable\n";
        else
            cout<<"immediately decodable\n";

		StrList.clear();
        a = false;
	}

	return 0;
}