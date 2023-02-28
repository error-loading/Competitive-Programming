// https://dmoj.ca/problem/dmopc16c4p5
// DMOPC '16 Contest 4 P5 - Migrant Mascot

#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>


using namespace std;

vector<pii> adj[200005];
int dist[200005];
long long INF = 0x3f3f3f3f;


int c, r, x, y, w, e;

int main() {
    cin >> c >> r;
    for (int i = 0; i<r; i++) {
        cin >> x >> y >> w;
        adj[x].emplace_back(w, y);
        adj[y].emplace_back(w, x);
    }
    priority_queue<pii, vector<pii>, less<pii>> pq;
    memset(dist, -INF, sizeof dist);
    pq.emplace(INF, 1);
    dist[1] = 0;
    while (!pq.empty()) {
        auto [dis, node1] = pq.top(); pq.pop();
        for (auto [cost, node2] : adj[node1]) {
            if (dist[node2] < min(dis, cost)) {
                dist[node2] = min(dis, cost);
                pq.emplace(min(dis, cost), node2);
            }
        }
    }
    for (int i = 1; i<= c; i++) {
        if (i==1){
         cout << 0 << endl;
         continue;
        }
        cout << dist[i] << endl;
    }

    return 0;
}