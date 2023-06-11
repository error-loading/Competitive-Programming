#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MM = 1e5 + 5;

int N, M, x, y, dp[MM];
vector<int> adj[MM];
bool visited[MM];

int dfs(int N) {
    if (dp[N] != -1) return dp[N];

    for (int node : adj[N]) {
        dp[N] = max(dp[N], dfs(node) + 1);
    }

    if (dp[N] != -1) return dp[N];
    return 0;

}

signed main() {
    cin >> N >> M;
    memset(dp, -1, sizeof dp);
    memset(visited, false, sizeof visited);

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int ans = 0;


    for (int i = 1; i <= N; i++) {
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;
}