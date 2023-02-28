// https://dmoj.ca/problem/wc18c4s1
// WC '18 Contest 4 S1 - World of StarCraft

#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m, k, a, b, x, y, cur = 0, ttl=0;
vector<int> adj[100005];
string race;

int preProcess[100005];

void graphTheory(int node) {
    for (auto i: adj[node]) {
        if (preProcess[i] == 0) {
            preProcess[i] = cur;
            graphTheory(i);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    cin >> race;
    for (int i = 0; i<m; i++) {
        cin >> a >> b;
        if (race[a-1] == race[b-1]) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    memset(preProcess, 0, sizeof preProcess);

    for (int i = 0; i<n; i++) {
        if (preProcess[i] == 0) {
            cur+= 1;
            preProcess[i] = cur;
            graphTheory(i);
        }
    }

    for (int i = 0; i<k; i++) {
        cin >> x >> y;
        if (preProcess[x] == preProcess[y]) ttl+=1;
    }

    cout << ttl << endl;

    return 0;
}