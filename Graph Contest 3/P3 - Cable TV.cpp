//https://dmoj.ca/problem/graph3p2
//https://dmoj.ca/problem/graph3p2

#include <iostream>
#include <cstring>
#include <vector>

#define pii pair<int, int>
using namespace std;

long long INF = 0x3f3f3f3f;

int n, m, x, y, c;
vector<int> edge[20005];
int dist[20005];


int main(){
    cin >> n >> m;
    for (int i = 0; i< m; i++) {
        cin >> x >> y >> c;
        edge[i].emplace_back(x);
        edge[i].emplace_back(y);
        edge[i].emplace_back(c);
    }

    memset(dist, INF, sizeof dist);
    dist[1] = 0;

    for (int j = 0; j<n; j++) {
        for (int i = 0; i< m; i++) {
            int node1, node2, cost; node1 = edge[i][0]; node2 = edge[i][1]; cost = edge[i][2];
            if (dist[node1] == INF) continue;
            if (dist[node2] > dist[node1] + cost) dist[node2] = dist[node1] + cost;
        }
    }
    cout << dist[n] << endl;

    return 0;
}