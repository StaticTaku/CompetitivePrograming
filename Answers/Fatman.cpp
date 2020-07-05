#include <bits/stdc++.h>
using namespace std;

bool visited[105];
int n, dist2[105][105];

bool check(int size) 
{
    memset(visited, 0, sizeof visited);
    visited[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int crnt = q.front(); q.pop();
        for (int i = 0; i < n+2; i++) {
            if (!visited[i] && dist2[i][crnt] < size) 
            { 
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return !visited[n+1];
}

int main() 
{
    int t, l, w;
    scanf("%d", &t);
    for (int q = 1; q <= t; q++) 
    {
        scanf("%d %d %d", &l, &w, &n);
        int array[n+2][2];
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &array[i][0], &array[i][1]);

        for (int i = 0; i < n; i++) 
        {
            for (int j = i+1; j < n; j++) 
            {
                dist2[i][j] = dist2[j][i] = (array[i][0]-array[j][0])*(array[i][0]-array[j][0]) + (array[i][1]-array[j][1])*(array[i][1]-array[j][1]);
            }
            dist2[i][n] = dist2[n][i] = (array[i][1])*(array[i][1]); 
            dist2[i][n+1] = dist2[n+1][i] = (w-array[i][1])*(w-array[i][1]);
        }
        dist2[n][n+1] = dist2[n+1][n] = w*w;

        int s = 0, e = w*w;

        while (e-s > 1) 
        {
            int mid = (e - s) / 2 + s;
            if (check(mid)) 
                s = mid;
            else 
                e = mid-1;
        }
        printf("Maximum size in test case %d is %0.4f.\n", q, (check(e) ? sqrt(e) : sqrt(s)));
    }
}
