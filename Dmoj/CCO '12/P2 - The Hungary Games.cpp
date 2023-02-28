// https://dmoj.ca/problem/cco12p2
// CCO '12 P2 - The Hungary Games

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

#define pii pair<int, int>
using namespace std;


long long INF = 0x3f3f3f3f;

vector<pii> adj[20005];
pii dist[20005];

int n, m, x, y, w;


int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    cin >> n >> m;
    for (int x = 0; x < 20005; x++) dist[x] = {INF, INF};
    for (int i = 0; i< m; i++) {
        cin >> x >> y >> w;
        adj[x].emplace_back(w, y);
    }
    queue<pii> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [dis, node1] = pq.front(); pq.pop();
        for (auto [cost, node2] : adj[node1]){
            if (dist[node2].first > cost+ dis) {
                dist[node2].second = dist[node2].first;
                dist[node2].first = cost + dis;
                pq.emplace(cost+dis, node2);
            } else if (dist[node2].first < cost + dis && dist[node2].second > cost + dis) {
                dist[node2].second = cost + dis;
                pq.emplace(cost+ dis, node2);
            }
        }
    }

    if (dist[n].second == INF) cout << -1 << endl;
    else cout << dist[n].second << endl;


    return 0;
}