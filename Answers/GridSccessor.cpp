#include <iostream>
#include <vector>

using namespace std;

int N;
char grid[100000][3][3];
int x[4] = { -1,0,0,1 };
int y[4] = { 0,1,-1,0 };

bool done(int l) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[l][i][j] == '1') return false;
	return true;
}

int f(int l) {
    if (done(l)) return -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cell = 0;
            for (int k = 0; k < 4; k++) {
                int r = i + x[k], c = j + y[k];
                if (r >= 0 && r < 3 \
                    && c >= 0 && c < 3 \
                    && grid[l][r][c] == '1') {
                    cell++;
                }
            }
            grid[l + 1][i][j] = cell % 2 == 1 ? '1' : '0';
        }
    }
    return 1 + f(l + 1);
}
void solve()
{
	cin >> N;

	while (N--)
	{
		cin.ignore();

		for (int i = 0; i < 3; i++)
			cin >> grid[0][i];

        cout << f(0) << "\n";
	}
}
int main()
{
    solve();
}