#include <bits/stdc++.h>
using namespace std;

const int MM = 10;

#define pii pair<int, int>
#define tii tuple<int, int, int>

int startX, startY, endX, endY, x, y, dis;
bool visited[MM][MM];
pii moves[] = {{-1, -2}, {-1, 2}, {1, 2}, {1, -2}, {2, 1}, {-2, -1}, {2, -1}, {-2, 1}};

bool in_range(int x, int y) {
    if (x <= 0 || x > 8 || y <= 0 || y > 8) {
        return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    memset(visited, false, sizeof visited);
    cin >> startX >> startY;
    cin >> endX >> endY;

    queue<tii> q;
    q.emplace(startX, startY, 0);
    visited[startX][startY] = true;
    while (!q.empty()) {
        tie(x, y, dis) = q.front(); q.pop();

        if (x == endX && y == endY) {
            cout << dis << endl;
            return 0;
        }

        for (auto [moveX, moveY] : moves) {
            if (in_range(x + moveX, y + moveY) && !visited[x + moveX][y + moveY]) {
                q.emplace(x + moveX, y + moveY, dis + 1);
                visited[x + moveX][y + moveY] = true;
            }
        }
    }
}