// https://dmoj.ca/problem/vmss7wc16c3p3
// VM7WC '16 #3 Gold - Hello, Officer.

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define pii pair<int, int>
using namespace std;

long long INF = 0x3f3f3f3f;

int n, m, a, b, q, x, y, c;
vector<pii> adj[2005];
int dist[2005];


int main(){
    cin >> n >> m >> b >> q;
    for (int i = 0; i< m; i++) {
        cin >> x >> y >> c;
        adj[x].emplace_back(y, c);
        adj[y].emplace_back(x, c);
    }

    memset(dist, INF, sizeof dist);
    dist[b] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.emplace(0, b);

    while (!pq.empty()) {
        auto [dis, node] = pq.top(); pq.pop();
        for (auto[node2, cost] : adj[node]) {
            if (dis + cost < dist[node2]) {
                dist[node2] = dist[node] + cost;
                pq.emplace(dist[node2],node2);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> a;
        if (dist[a] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a] << endl;
        }
    };

    return 0;
}