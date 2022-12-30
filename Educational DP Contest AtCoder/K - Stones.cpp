// https://dmoj.ca/problem/dpk
// Educational DP Contest AtCoder K - Stones

#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    bool dp[k+1];
    
    memset(dp, false, sizeof(dp));

    int stones[n];
    for (int i = 0; i < n; i++) cin >> stones[i];

    for (int i = 1; i <= k; i++) {
        for (auto j: stones) {
            if (i-j >= 0 && !dp[i - j]) {
                dp[i] = true;
            }
        }
        
    }

    if (dp[k]) {
        cout << "First";
    } else {
        cout << "Second";
    }
    return 0;
}