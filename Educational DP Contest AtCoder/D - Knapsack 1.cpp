// https://dmoj.ca/problem/dpd
// Educational DP Contest AtCoder D - Knapsack 1

#include <iostream>
using namespace std;

long long N, W, dp[105][100005];

int main() {
    cin >> N >> W;

    for (int i =1; i <=N; ++i) {
        int w, v; cin >> w >> v;
        for (int j = 1; j <=W; ++j) {
            dp [i][j] = dp[i-1][j];
            if (j>=w) dp[i][j] = max(dp[i][j], dp[i-1][j-w]+v);
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}