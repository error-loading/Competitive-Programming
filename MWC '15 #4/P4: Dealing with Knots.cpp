#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, a, b, x, y, node;
vector<int> adj[1005];
bool visited[1005];

int main(){
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    cin >> x >>y;
    memset(visited, false,sizeof visited);
    deque<int> dq;
    dq.push_back(x);
    visited[x] = true;
    while (!dq.empty()) {
        node = dq.front();
        dq.pop_front();
        if (node == y) {
            cout << "Tangled" << endl;
            return 0;
        }
        for (auto i: adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                dq.push_back(i);
            }
        }
    }
    cout << "Not Tangled" << endl;

    return 0;
}