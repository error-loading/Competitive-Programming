// https://dmoj.ca/problem/ccc17s4
// CCC '17 S4 - Minimum Cost Flow

/********   All Required Header Files ********/
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <string>
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
#include <limits>
#include <climits>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/* TYPES */
#define ll long long
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define mii map<int, int>

typedef array<int, 4> E;
const int MM=1e5 + 3;
int N, M, D, p[MM], last; vector<E> edge;

int find_set(int d) {
    if (d!= p[d]) p[d] = find_set(p[d]);
    return p[d];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> D;
    for (int i = 1; i<=N; i++) p[i] = i;
    for (int i = 1, u, v, w; i<=M; i++) {
        cin >> u >> v >> w;
        edge.push_back({w, i>=N, u, v});
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (int i = 0; i<edge.size(); i++) {
        int t = edge[i][1], u = edge[i][2], v = edge[i][3];
        int fu = find_set(u), fv = find_set(v);
        if (fu != fv) {
            p[fu] = fv; ans +=t; last = i;
        }
    }
    if (edge[last][1]) {
        for (int i = 1; i<=N; i++) p[i] = i;
        for (int i = 0; i<last; i++) {
            auto [w, t, u, v] = edge[i];
            if (!t || w < edge[last][0]) {
                int fu = find_set(u), fv = find_set(v);
                if (fu != fv) p[fu] = fv;
            }
        }
        for (int i = last+1; i<edge.size(); i++) {
            auto [w, t, u, v] = edge[i];
            if (!t && w<=D) {
                int fu = find_set(u), fv = find_set(v);
                if (fu != fv) {ans --; break;}
            }
        }
    }
    cout << ans << endl;
}