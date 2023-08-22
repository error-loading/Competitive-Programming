#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 105;
int N, M, x, y; 
bool grid[MAXSZ][MAXSZ];

void calc(int x, int y, int mx, int my) {
    if (x + mx >= 0 && x + mx < N && y + my >= 0 && y + my < N) {
        grid[x + mx][y + my] = true;
        calc(x + mx, y + my, mx, my);
    }
}

signed main() {
    cin >> N >> M; 
    while (M--) {
        cin >> x >> y;
        x--;y--;
        grid[x][y] = true;
        calc(x, y, 1, 1);
        calc(x, y, 1, -1);
        calc(x, y, -1, -1);
        calc(x, y, -1, 1);
        calc(x, y, -1, 0);
        calc(x, y, 1, 0);
        calc(x, y, 0, 1);
        calc(x, y, 0, -1);
    }

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!grid[i][j]) ans++;
        }
    }

    cout << ans << endl;
}