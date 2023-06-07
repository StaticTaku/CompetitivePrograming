
#include <bits/stdc++.h>
using namespace std;

char T[100020];
int m, b[100020];

void kmpPreprocess() 
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m) 
    {
        while (j >= 0 && T[m - i - 1] != T[m - j - 1]) 
            j = b[j]; 
        i++;   j++;
        b[i] = j;
    }
}
 
int kmpSearch() 
{
    int i = 0, j = 0;
    while (i < m) 
    {
        while (j >= 0 && T[i] != T[m - j - 1])
            j = b[j];
        i++;
        j++;
    }
    return i - j;
}
 
int main() {
    while (true) 
    {
        T[0] = 0;
        scanf("%s", T);
        m = 0;

        while (T[m]) 
        {
            ++m;
        }

        if (m == 0)
            break;

        kmpPreprocess();
        int index = kmpSearch();
        printf("%s", T);

        for (int i = index - 1; i >= 0; --i)
            printf("%c", T[i]);
        printf("\n");
    }
    return 0;
}