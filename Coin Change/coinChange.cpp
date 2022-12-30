// https://dmoj.ca/problem/cchange
// Coin Change

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int x; int n; cin >> x >> n;
    int coins[n];
    int dp[x+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i<n; i++){
        cin >> coins[i];
    }

    for (int i = 0; i < x+1; i++) {
        for (int j = 0; j < n; j++) {
            int coin = coins[j];
            if (i+coin <= x) {
                if (dp[i+coin] != -1) dp[i+coin] = min(dp[i+coin], dp[i] + 1);
                else dp[i+coin] = dp[i] +1;
            }
        }
    }
    cout << dp[x];

    return 0;
}