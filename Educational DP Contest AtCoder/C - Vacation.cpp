// https://dmoj.ca/problem/dpc
// Educational DP Contest AtCoder C - Vacation

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int dp[n+1][3];
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    for (int i = 1; i<=n; i++){
        int a; int b; int c; cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1] +a, dp[i-1][2] +a);
        dp[i][1] = max(dp[i-1][0] +b, dp[i-1][2] +b);
        dp[i][2] = max(dp[i-1][1] +c, dp[i-1][0] +c);
    }

    int greatest = 0;
    greatest = max(greatest, dp[n][0]);
    greatest = max(greatest, dp[n][1]);
    greatest = max(greatest, dp[n][2]);

    cout << greatest;

    return 0;
}