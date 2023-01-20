#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

#define pii pair<int, int>


using namespace std;

vector<pii> adj[10005];
int dist[10005];
long long INF = 0x3f3f3f3f;


int c, r, d, x, y, w, e;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> r >> d;
    for (int i = 0; i<r; i++) {
        cin >> x >> y >> w;
        adj[x].emplace_back(w, y);
        adj[y].emplace_back(w, x);
    }
    priority_queue<pii, vector<pii>, less<pii>> pq;
    memset(dist, -INF, sizeof dist);
    pq.emplace(INF, 1);
    dist[1] = INF;
    while (!pq.empty()) {
        auto [dis, node1] = pq.top(); pq.pop();
        if (dis < dist[node1]) continue;
        for (auto [cost, node2] : adj[node1]) {
            if (dist[node2] < min(dis, cost)) {
                dist[node2] = min(dis, cost);
                pq.emplace(min(dis, cost), node2);
            }
        }
    }
    int small = INF;
    for (int i = 0; i< d; i++) {
        cin >> e;
        small = min(small, dist[e]);
    }
    cout << small << endl;

    return 0;
}