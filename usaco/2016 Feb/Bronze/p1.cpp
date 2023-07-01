// http://www.usaco.org/index.php?page=viewproblem2&cpid=615
#include <bits/stdc++.h>
using namespace std;

const int MM = 1005;
int X, Y, M, dp[MM], big = 0;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    cin >> X >> Y >> M;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int i = 0; i <= M; i++) {
        if (dp[i]) {
            dp[i + X] = 1;
            dp[i + Y] = 1;
            if (i + X <= M) big = max(i + X, big);
            if (i + Y <= M) big = max(i + Y, big);
        }
    }

    cout << big << endl;
}