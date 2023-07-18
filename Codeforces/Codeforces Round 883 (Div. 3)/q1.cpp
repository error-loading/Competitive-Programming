#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;

    while (t--) {
        cin >> n;

        int ball_height = 0;
        int cut = 0;
        // vector<pair<int, int>> s1;

        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            if (a > b) cut++;
        }

        // sort(s1.begin(), s1.end(), greater<int>());

        // while (!ball_height) {

        // }
        cout << cut << endl;


    }
}