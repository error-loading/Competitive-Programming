#include <bits/stdc++.h>
using namespace std;

int M;
int freq[3][10];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M;
    memset(freq, -1, sizeof freq);

    for (int i = 0; i < 3; i++) {
        string s; cin >> s;

        for (int j = 0; j < s.size();j++) {
            int dig = s[j] - '0';
            if (freq[i][dig] == -1) {
                freq[i][dig] = j + 1;
            }
        }
    }

    int small = INT_MAX;

    for (int i = 0; i < 10; i++) {
        if (freq[1][i] != -1 && freq[0][i] != -1 && freq[2][i] != -1) small = min(small, max(freq[0][i], max(freq[1][i], freq[2][i])));
    }

    cout << small << endl;


}