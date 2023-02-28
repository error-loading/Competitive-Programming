// https://dmoj.ca/problem/dwite09c6p5
// DWITE '09 R6 #5 - Air Travel Planning

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <map>

using namespace std;

#define f first
#define s second


int E, w;
string x, y, node;

map<string, int> dists;
map<string, vector<pair<string, int>>> G;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> PQ;

int main() {

    for(int t = 0; t < 5; t++) {

        dists = map<string, int>();
        G = map<string, vector<pair<string, int>>>();
        PQ = priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>>();

        cin >> E;

        for (int i = 0; i < E; i++) {
            cin >> x >> y >> w;
            G[x].push_back({y, w});

            dists[x] = INT_MAX;
            dists[y] = INT_MAX;
        }

        dists["YYZ"] = 0;

        PQ.push({0, "YYZ"});

        while (!PQ.empty()) {

            node = PQ.top().s;
            PQ.pop();

            if (G.find(node) != G.end()) {
                for (pair<string, int> i : G[node]) {

                    if (dists[i.f] > dists[node] + i.s) {
                        dists[i.f] = dists[node] + i.s;
                        PQ.push({dists[i.f], i.f});
                    }

                }
            }

        }

        cout << dists["SEA"] << endl;

    }

    return 0;
}