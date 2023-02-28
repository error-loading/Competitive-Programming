// https://dmoj.ca/problem/dmopc18c3p2
// DMOPC '18 Contest 3 P2 - Bob and French Class

#include <iostream>
using namespace std;

int dp[100001][3];
int french[100001];
int english[100001];

int main() {
    int n; cin >>n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 0; i< n; i++) cin >> french[i];
    for (int i = 0; i< n; i++) cin >> english[i];

    for (int i = 0; i < n; i++) {
        dp[i+1][2] = dp[i][1] + french[i];
        dp[i+1][1] = dp[i][0] + french[i];

        dp[i+1][0] = max(max(dp[i][2] + english[i], dp[i][1] + english[i]), dp[i][0] + english[i]);
    }

    long long greatest = -100000000;

    for (long long i: dp[n])
        greatest = max(greatest, i);
    cout << greatest;
    return 0;
}