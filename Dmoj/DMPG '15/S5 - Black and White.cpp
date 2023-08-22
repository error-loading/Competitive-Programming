#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 10003;
int N, M, x, y, w, h;
bool grid[MAXSZ][MAXSZ];

signed main() {
    cin >> N >> M;

    while (M--) {
        cin >> x >> y >> w >> h;
        grid[x + 1][y + 1] ^= 1;
        grid[x + w + 1][y + 1] ^= 1;
        grid[x + 1][y + h + 1] ^= 1;
        grid[x + w + 1][y + h + 1] ^= 1;
    }

    int ans = 0;

    for (int i = 1; i <= N + 2; ++i) {
        for (int j = 1; j <= N + 2; ++j) {
            grid[i][j] ^= grid[i - 1][j] ^ grid[i][j - 1] ^ grid[i - 1][j - 1];
            ans+= grid[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}