#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 12;
int grid[MAXSZ][MAXSZ], N, ans;
bool visited[MAXSZ];

void rec(int start, int cur, int len) {
    visited[cur] = true;

    for (int i = 0; i < N; ++i) {
        if (grid[cur][i]) {
            if (start == i) {
                ans++;
            }
            else if (!visited[i]) rec(start, i, len + 1);
        }
    }

    visited[cur] = false;
}

signed main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        rec(i, i, 0);
        visited[i] = true;
    }

    cout << ans << endl;

    return 0;
}