// https://dmoj.ca/problem/ddrp3
// Double Doors Regional P3 - Tudor and the Pusheens

#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

#define ll long long
#define pii pair<ll,ll>


using namespace std;

ll n, m, x, y, s, t, node, dis;
vector<ll> adj[1000005];
bool visited[1000005];


int main() {
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i< m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s >> t;
    deque<pii> dq;
    dq.push_back(make_pair(s, 0));
    visited[s] = true;
    while (!dq.empty()) {
        node = dq.front().first;
        dis = dq.front().second;
        dq.pop_front();
        if (node == t) {
            cout << m-dis << endl;
            return 0;

        }

        for (auto i: adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                dq.push_back(make_pair(i, dis+1));
            }
        }

    }

}