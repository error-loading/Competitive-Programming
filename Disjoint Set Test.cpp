// https://dmoj.ca/problem/ds2
// Disjoint Set Test

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

typedef array<int, 3> E;
const int MM=1e5 + 3;
int N, M, p[MM], last; vector<pii> edge;

int find_set(int d) {
    if (d!= p[d]) p[d] = find_set(p[d]);
    return p[d];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i<=N; i++) p[i] = i;
    for (int i = 1, u, v; i<=M; i++) {
        cin >> u >> v;
        edge.push_back({u, v});
    }
    vector<int> ans;
    for (int i = 0; i<edge.size(); i++) {
        auto [u, v] = edge[i];
        int fu = find_set(u), fv = find_set(v);
        if (fu != fv) {
            p[fu] = fv;
            ans.push_back(i + 1);
        }
    }

    if (ans.size() != N-1) { cout << "Disconnected Graph" << endl; return 0;}
    for (auto i : ans) {
        cout << i << endl;
    }
}