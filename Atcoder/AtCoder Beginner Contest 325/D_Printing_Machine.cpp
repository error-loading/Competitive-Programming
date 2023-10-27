#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define pii pair<int, int>
#define mp make_pair

int N;
vector<pii> a;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int t, w; cin >> t >> w;
        a.push_back(mp(t, t + w));
    }

    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<>>  q;
    int ttl = 0, ind = 0;

    // i is cur time
    for (int i = 0;;i++) {
        if (q.empty()) {
            if (ind == N) break;
            i = a[ind].first;
        }

        while (ind < N && a[ind].first == i) q.push(a[ind++].second);

        // remove everything outside of range
        while (!q.empty() && q.top() < i) q.pop();

        // increment answer
        if (!q.empty()) {ttl++; q.pop();}
    }

    cout << ttl << endl;
}