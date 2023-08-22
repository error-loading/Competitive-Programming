#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = 1505;
int N, M, grid[MAXSZ][MAXSZ];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (!grid[i][j]) {
                int pos = max(grid[i - 1][j], grid[i][j - 1]);
                int req = 0;

                if (grid[i][j + 1] == 0) req = grid[i + 1][j];
                else if (grid[i + 1][j] == 0) req = grid[i][j + 1];
                else req = min(grid[i][j + 1], grid[i + 1][j]);

                if (req != 0 && pos + 1 >= req) {
                    cout << - 1 << endl;
                    return 0;
                }

                grid[i][j] = pos + 1;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i + 1 <= N && grid[i][j] >= grid[i + 1][j]) {
                cout << - 1 << endl;
                return 0;
            } 

            if (j + 1 <= M && grid[i][j] >= grid[i][j + 1]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }



    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }


}