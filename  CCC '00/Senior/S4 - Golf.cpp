// https://dmoj.ca/problem/ccc00s4
// CCC '00 S4 - Golf

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int goal; int clubs; cin >> goal >> clubs;
    int club[clubs];

    int dp[goal+1];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for (int i = 0; i<clubs; i++) {
        cin >> club[i];
    }

    for (int i = 0; i<=goal; i++) {
        for (auto j: club) {
            if (i+j <= goal && dp[i] !=-1) {
                if (dp[i+j] != -1) min(dp[i+j], dp[i]+1);
                else dp[i+j] = dp[i] + 1;
            }
        }
    }

    if (dp[goal] == -1) {
        cout << "Roberta acknowledges defeat.";
    } else cout << "Roberta wins in " << dp[goal] << " strokes.";

    return 0;
}