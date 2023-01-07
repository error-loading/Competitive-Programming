// https://dmoj.ca/problem/hci16taxi
// HCI '16 - Taxi

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
using namespace std;

long long INF = 0x3f3f3f3f;

int v, e, p, d, r, a, b, c;
vector<pii> adj[100005];
int dist[100005];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int ttl = 0;

int main(){
    cin >> v >> e >> p >> d >> r;
    for (int i = 0; i< e; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }

    memset(dist, INF, sizeof dist);
    dist[p] = 0;
    pq.emplace(0, p);

    while (!pq.empty()) {
        auto [dis, node1] = pq.top(); pq.pop();
        for (auto [cost, node2] : adj[node1]) {
            if (dist[node2] > dis+cost) {
                dist[node2] = dis+cost;
                pq.emplace(dis+cost, node2);
            }
        }
    }
    if (dist[d] == INF) {
        cout << "Nooooooooo!!!" << endl;
        return 0;
    }

    ttl+=3;

    if (dist[d] > 10) {
        ttl+=20; ttl+=dist[d] - 10;
    } else {
        ttl+=dist[d] * 2;
    }

    memset(dist, INF, sizeof dist);
    dist[d] = 0;
    pq.emplace(0, d);

    while (!pq.empty()) {
        auto [dis, node1] = pq.top(); pq.pop();
        for (auto [cost, node2] : adj[node1]) {
            if (dist[node2] > dis+cost) {
                dist[node2] = dis+cost;
                pq.emplace(dis+cost, node2);
            }
        }
    }

    if (dist[r] == INF) {
        cout << ttl << endl;
        cout << "Yippee!!!" << endl;
        return 0;
    }

    ttl+=dist[r];
    cout << ttl << endl;

}