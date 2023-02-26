// https://dmoj.ca/problem/ccc07s5
// CCC '07 S5 - Bowling for Numbers

/********   All Required Header Files ********/
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <assert.h>

using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7;
const int MM = 3e4 + 4;
int T, N, K, W, psa[MM], dp[505][MM];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (cin >> T; T--;){
        cin >> N >> K >> W;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<=N; i++) {
            cin >> psa[i]; psa[i] += psa[i-1];
        }
        for (int i =1; i <=K; i++) {
            for (int j = 1; j<=N; j++) {
                if (j <= W) dp[i][j] = psa[j];
                else dp[i][j] = max(dp[i][j-1], psa[j] - psa[j-W] + dp[i-1][j-W]);
            }
        }
        cout << dp[K][N] << endl;
    }
    return 0;
}