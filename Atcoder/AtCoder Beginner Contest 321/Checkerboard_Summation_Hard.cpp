#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MM = 3e3 + 2;
int M, N, op, bit[MM][MM], a[MM][MM];

void update(int r, int c, int val) {
    for (int i = r; i <= M; i += (i&-i)) {
        for (int j = c; j <= N; j += (j&-j)) {
            bit[i][j] += val;
        }
    }
}

int sum(int r, int c) {
    int ttl = 0;
    for (int i = r; i > 0; i -= (i & -i)) {
        for (int j = c; j > 0; j -= (j & -j)) {
            ttl += bit[i][j];
        }
    }
    return ttl;
}

int query(int r1, int c1, int r2, int c2) { 
    return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1); 
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> M >> N;
    cin >> op;

    memset(a, 0, sizeof a);

    while (op != 0) {
        if (op == 1) {
            int r, c, x; cin >> r >> c >> x;
            if ((r + c) % 2) x *= -1;

            update(r, c, x - a[r][c]);
            a[r][c] = x;
        } else if (op == 2) {
            int l, b, r, t; cin >> l >> b >> r >> t; 
            cout << ((l + b) % 2 ? -query(l, b, r, t) : query(l, b, r, t)) << endl;
        }
        cin >> op;
    }

}