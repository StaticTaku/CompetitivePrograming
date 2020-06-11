#include <bits/stdc++.h>
using namespace std;

int main() 
{
    char n1[100], n2[100];
    string s1, s2;
    int count = 1;
    int AdjMat[55][55];
    map<string, int> Idx;
    int P, R;

	while (true) 
    {
        cin >> P >> R;
        if(P == 0 && R == 0)
            return 0;

		Idx.clear();
		memset(AdjMat, 32, sizeof AdjMat);
		int idx = 0;

		for (int i = 0; i < R; i++) 
        {
			scanf("%s", n1);  scanf("%s", n2);
			s1 = string(n1);  s2 = string(n2);

			if (Idx.count(s1) == 0) {
				Idx[s1] = idx++;
			}
			if (Idx.count(s2) == 0) {
				Idx[s2] = idx++;
			}

			AdjMat[Idx[s1]][Idx[s2]] = 1;
			AdjMat[Idx[s2]][Idx[s1]] = 1;
		}

		for (int k = 0; k < P; k++)
			for (int i = 0; i < P; i++)
				for (int j = 0; j < P; j++)
					AdjMat[i][j] = min(AdjMat[i][j],AdjMat[i][k] + AdjMat[k][j]);

		int maximum = -1;
		printf("Network %d: ", count++);
		for (int i = 0; i < P; i++) 
        {
			for (int j = i + 1; j < P; j++) 
            {
				maximum = max(maximum, AdjMat[i][j]);
			}
		}
		if (maximum > 5e8)
            cout << "DISCONNECTED\n\n";
		else
            cout << maximum << "\n\n";
	}

	return 0;
}