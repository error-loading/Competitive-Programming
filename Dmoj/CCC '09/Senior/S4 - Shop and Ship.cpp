// https://dmoj.ca/problem/ccc09s4
// CCC '09 S4 - Shop and Ship

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define INF 1000000

using namespace std;

int n, t, x, y, z, k, p,price, d;

vector<pii> adj[5001];
int dist[5001];
vector<pii> pencil;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i<t; i++) {
        cin >> x >> y >> z;
        adj[x].emplace_back(z, y);
        adj[y].emplace_back(z, x);

    }
    cin >> k;
    for (int i = 0; i<k; i++) {
        cin >> p >> price;
        pencil.emplace_back(p,price);
    }
    cin >> d;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(dist, INF, sizeof dist);
    dist[d] = 0;

    pq.emplace(0, d);
    while (!pq.empty()) {
        auto [cost, node1] = pq.top(); pq.pop();
        if (cost > dist[node1]) continue;
        for (auto [dis, node2] : adj[node1]) {
            if (dist[node2] > cost + dis) {
                dist[node2] = cost+dis;
                pq.emplace(dist[node2], node2);
            }
        }
    }

    int mini = INF;

    for (auto [z, pz] : pencil) {
        mini = min(mini, dist[z] + pz);
    }

    cout << mini << endl;

    return 0;
}