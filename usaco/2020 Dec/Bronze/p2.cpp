// http://www.usaco.org/index.php?page=viewproblem2&cpid=1060
#include <bits/stdc++.h>
using namespace std;

const int MM = 1e2 + 5;
int N, arr[MM];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    set<pair<int, int>> cnt;

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            int sum = 0;

            for (int k = i; k <= j; k++) sum += arr[k];

            if (sum % (j - i + 1) == 0) {
                int avg = sum / (j - i + 1);

                for (int k = i; k <= j; k++) {
                    if (arr[k] == avg) {
                        cnt.insert({i, j});
                    }
                }
            }
        }
    }

    cout << cnt.size() << endl;
}