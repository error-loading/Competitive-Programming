// https://dmoj.ca/problem/ccc15s4
// CCC '15 S4 - Convex Hull

/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define pii tuple<int, int, int>
using namespace std;


long long INF = 0x3f3f3f3f;

vector<pii> adj[2005];
long long dist[2005][205];

long long k, n, m, x, y, w, h, a, b;


int main() {
    cin >> k >> n >> m;
    memset(dist, 0x3f3f, sizeof dist);
    for (long long i = 0; i< m; i++) {
        cin >> x >> y >> w >> h;
        adj[x].emplace_back(w, y, h);
        adj[y].emplace_back(w, x, h);
    }
    cin >> a >> b;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, a, 0);
    dist[a][0] = 0;

    while (!pq.empty()) {
        auto [dis, node1, h] = pq.top(); pq.pop();
        for (auto [cost, node2, h2] : adj[node1]){
            for (int i = 0; i< k-h2; i++) {
                if (dist[node2][i+h2] > cost + dist[node1][i]) {
                    dist[node2][i+h2] = dist[node1][i] + cost;
                    pq.emplace(dist[node2][i+h2], node2, h2);
                }
            }
        }
    }
    long long big = INF;
    for (int i = 0; i<205; i++) {
        big = min(big, dist[b][i]);
    }
    if (big == INF) {
        cout << -1 << endl;
    } else {
        cout << big << endl;
    }


    return 0;
}