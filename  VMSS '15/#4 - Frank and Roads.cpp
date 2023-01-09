// https://dmoj.ca/problem/vmss15c1p4
// https://dmoj.ca/problem/vmss15c1p4

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define pii pair<int, int>
#define INF 1000000

using namespace std;

int t, m, n, g, a, b, c;

int buildings[2005];

vector<pii> adj[2005];
int dist[2005];

int main() {
    cin >> t >> m >> n >> g;
    int buildings[g];
    for (int i = 0; i < g; i++) {
        cin >> buildings[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(dist, INF, sizeof dist);
    dist[0] = 0;

    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [cost, node1] = pq.top(); pq.pop();
        for (auto [dis, node2] : adj[node1]) {
            if (dist[node2] > cost + dis) {
                dist[node2] = cost+dis;
                pq.emplace(cost+dis, node2);
            }
        }
    }

    int ttl = 0;

    for (auto i : buildings) {
        if (dist[i] <= t) {
            ttl+=1;
        }
    }
    cout << ttl << endl;

    return 0;
}