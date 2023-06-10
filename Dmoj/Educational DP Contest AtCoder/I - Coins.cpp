#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MM = 3e3 + 5;
int N;

double dp[MM][MM], arr[MM];

signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1][0] = 1 - arr[1];
    dp[1][1] = arr[1];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][0] * (1 - arr[i]);
        dp[i][i] = dp[i-1][i-1] * arr[i];
    }

    for (int i = 1; i<= N; i++) {
        for (int j = 1; j< i; j++) {
            dp[i][j] = dp[i-1][j - 1] * (arr[i]) + dp[i - 1][j] * (1 - arr[i]);
        }
    }


    double ans = 0.0;

    for (int i = 1; i <= ceil(N * 0.5); i++) {
        ans += dp[N][N/2 + i];
    }


    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}