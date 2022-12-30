// https://dmoj.ca/problem/ccc13s4
// CCC '13 S4 - Who is Taller?

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n; int m; int x; int y; int p; int q; int node;
vector<int> adje[100001];
queue<int> que;
bool visited[100001];

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adje[x].push_back(y);
    }
    cin >> p >> q;

    que.push(p);
    visited[p] = true;

    while (!que.empty()) {
        node = que.front();
        que.pop();
        
        if (node == q) {
            cout << "yes" << endl;
            return 0;
        }

        for (auto i: adje[node]) {
            if (!visited[i]) {
                que.push(i);
                visited[i] = true;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    que.push(q);
    visited[q] = true;

    while (!que.empty()) {
        node = que.front();
        que.pop();

        if (node == p) {
            cout << "no" << endl;
            return 0;
        }

        for (auto i: adje[node]) {
            if (!visited[i]) {
                que.push(i);
                visited[i] = true;
            }
        }
    }

    cout << "unknown" << endl;


    return 0;
}
