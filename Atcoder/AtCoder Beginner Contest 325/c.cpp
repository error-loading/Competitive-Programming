#include <bits/stdc++.h>
using namespace std;

const int MM = 1e3 + 2;
int H, W; 
char a[MM][MM];
bool vis[MM][MM];

bool in_range(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W) return false;
    return true;
}

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (in_range(x + i, y + j) && a[x + i][y + j] == '#' && !vis[x + i][y + j]) dfs(x + i, y + j);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(vis, false, sizeof vis);
    cin >> H >> W;

    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; col++) {
            cin >> a[row][col];
        }
    }

    int ans = 0;

    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; col++) {
            if (a[row][col] == '#' && !vis[row][col]) {dfs(row, col); ans++;}
        }
    }

    cout << ans << endl;


}