// https://dmoj.ca/problem/dpe
// https://dmoj.ca/problem/dpe

#include <iostream>

using namespace std;

int n,w;
int items[100][2];
long long dp[100001];

int main() {

    cin >> n >> w;
    for (int i = 0; i < n; i ++){
        cin >> items[i][0] >> items[i][1];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int i = 0, wi, vi; i < n; i ++){
        wi = items[i][0];
        vi = items[i][1];
        for (int j = 1e5; j >= vi; j --){
            dp[j] = min(dp[j],dp[j-vi]+wi);
        }
    }

    for (int j = 1e5; j >= 0; j--){
        if (dp[j] <= w){
            cout << j; return 0;
        }
    }
    return 0;
}