// https://dmoj.ca/problem/sssp
// Single Source Shortest Path

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define pii pair<int, int>
using namespace std;

long long INF = 0x3f3f3f3f;

int n, m, a, b, c, node;
vector<pii> adj[1005];
int dist[1005];

int main(){
    cin >> n >> m;
    for (int i = 0; i< m; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    memset(dist, INF, sizeof dist);
    dist[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [dis, node] = pq.top(); pq.pop();
        for (auto[node2, cost] : adj[node]) {
            if (dis + cost < dist[node2]) {
                dist[node2] = dist[node] + cost;
                pq.emplace(dist[node2],node2);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << (dist[i] == 1061109567 ? -1 : dist[i]) << "\n";

    return 0;
}