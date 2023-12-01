#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MM = 1e3 + 2;
int a[MM][MM], dist_car[MM][MM], dist_train[MM][MM];
int N, A, B, C;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B >> C;

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cin >> a[row][col];
            dist_car[row][col] = a[row][col] * A;
            dist_train[row][col] = a[row][col] * B + C;
        }
    }

    int bst = LONG_MAX;

    for (int col = 0; col < N; ++col) {
        cout << col << " " << dist_car[0][col] << " " << dist_train[col][N - 1] << endl;
        bst = min(bst, dist_car[0][col] + dist_train[col][N - 1]);
    }

    cout << bst << endl;
}

