// https://dmoj.ca/problem/gfssoc2s4
// GFSSOC '15 Fall S4 - Mostly Talking

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


long long INF = 0x3f3f;

vector<pii> adj[500005];
vector<pii> adj2[500005];
int distStart[500005];
int distEnd[500005];

int n, m, x, y, w, d;


int main() {
    cin >> n >> m;
    memset(distStart, 0x3f3f, sizeof distStart);
    memset(distEnd, 0x3f3f, sizeof distEnd);
    for (int i = 0; i< m; i++) {
        cin >> x >> y >> w;
        adj[x].emplace_back(w, y);
        adj2[y].emplace_back(w, x);
    }
    queue<pii> pq;
    pq.emplace(0, 1);
    distStart[1] = 0;
    while (!pq.empty()) {
        auto [dis, node1] = pq.front(); pq.pop();
        for (auto [cost, node2] : adj[node1]){
            if (distStart[node2] > cost+ dis) {
                distStart[node2] = cost + dis;
                pq.emplace(cost+dis, node2);
            }
        }
    }
    queue<pii> pqq;
    pqq.emplace(0, n);
    distEnd[n] = 0;
    while (!pqq.empty()) {
        auto [dis, node1] = pqq.front(); pqq.pop();
        for (auto [cost, node2] : adj2[node1]){
            if (distEnd[node2] > cost+ dis) {
                distEnd[node2] = cost + dis;
                pqq.emplace(cost+dis, node2);
            }
        }
    }

    cin >> d;
    int best = distStart[n];
    for (int i = 0; i<d; i++) {
        cin >> x >> y >> w;
        best = min(best, distStart[x] + w + distEnd[y]);
    }
    cout << (best == 0x3f3f3f3f ? -1 : best) << endl;

    return 0;
}
