// https://dmoj.ca/problem/dmopc15c3p3
// DMOPC '15 Contest 3 P3 - Dimethylbenzene


#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>

using namespace std;

int n, m, x, y, node, dis;
vector<int> adje[100001];
queue<pii> que;
bool visited[100001];

int main() {
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adje[x].push_back(y);
    }

    que.push(make_pair(1, 0));

    while (!que.empty()) {
        node = que.front().first;
        dis = que.front().second;
        que.pop();

        if (node == 1 && dis >= 6) {
            cout << "YES" << endl;
            return 0;
        }

        for (auto i: adje[node]) {
            if (!visited[i]) {
                que.push(make_pair(i, dis+1));
                visited[i] = true;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}