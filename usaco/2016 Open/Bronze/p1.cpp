// http://www.usaco.org/index.php?page=viewproblem2&cpid=639
#include <bits/stdc++.h>
using namespace std;

const int MM = 1e3 + 5;

int N, K, x, big = 0;
vector<int> arr;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = i; j < N; j++) {
            if (arr[i] + K >= arr[j]) cnt += 1;
            else break;
        }

        big = max(big, cnt);
    }

    cout << big << endl;
}