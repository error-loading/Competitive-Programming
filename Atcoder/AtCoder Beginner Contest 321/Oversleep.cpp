#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define endl "\n"
#define pii pair<int, int>
#define tii tuple<int, int, int>

const int MM = 1e3 + 2;

int N, M, dist[MM];
char a[MM][MM];
bool visited[MM][MM];
pii s = {};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool in_range(int x, int y) {
    if (x <= 0 || x > N || y <= 0 || y > M) {
        return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    memset(visited, false, sizeof visited);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 's') s = {i, j};
        }
    }

    queue<tii> q;
    q.push(make_tuple(s.fi, s.se, 0));
    visited[s.fi][s.se] = true;

    while (!q.empty()) {
        int x, y, dis;
        get<0>(q.front()) = x; get<1>(q.front()) = y; get<2>(q.front()) = dis; q.pop();

        if (a[x][y] == 'e') {
            cout << dis << endl;
            return 0;
        }

        for (int move = 0; move < 4; move++) {
            if (!visited[x + dx[move]][y + dy[move]] && in_range(x + dx[move], y + dy[move])) {
                visited[x + dx[move]][y + dy[move]] = true;

                q.push(make_tuple(x + dx[move], y + dy[move], dis + 1));
            }
        }


    }

    cout << -1 << endl;



}