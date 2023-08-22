#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

map<int, int> freq;
int N, L, S, a, b, s;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> S;

    int last = 0;

    while (N--) {
        cin >> a >> b >> s;
        freq[a] += s;
        freq[b + 1] -= s;

        last = max(last, b + 1);
    }

    int ans = 0;
    int prev_val = 0;
    int prev_house = 0;


    for (auto [house, val] : freq) {
        if (prev_val < S) {
            ans += house - prev_house;
        }

        prev_val += val;
        prev_house = house;
    }

    ans += L - last;

    cout << ans << endl;

    return 0;
}