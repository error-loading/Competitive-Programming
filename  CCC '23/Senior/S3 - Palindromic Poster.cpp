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
const int MM = 2003;
int N, M, R, C, cntR, cntC; char g[MM][MM];

void fail() { cout << "IMPOSSIBLE" << endl; exit(0);}
// int checkR(int i) {
//     for ()
// }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(g, 'a', sizeof g);
    for (int i = R+1; i<=N; i++) g[i][M] = g[i][1] + 1;
    for (int i = C+1; i<=M; i++) g[N][i] = g[1][i] + 1;
    if (R!=N && C==0) g[N][M] = 'c';
    if (R == N && C != 0) {
        if (M % 2 == 0 && C % 2 != 0) fail();
        for (int i = 1; i<= M; i++) {
            if (i <= C/2 || i> M-C/2) g[N][i] = g[1][i];
            else g[N][i] = g[1][i] + 1;
        }
        if(C % 2) g[N][(M+1)/2] = g[1][(M+1)/2];
    }

    if (R != 0 && C == M) {
        if (N % 2 == 0 && R % 2 != 0) fail();
        for (int i = 1; i<= N; i++) {
            if (i <= R/2 || i> N-R/2) g[i][M] = g[i][1];
            else g[i][M] = g[1][i] + 1;
        }
        if(R % 2) g[(N+1)/2][M] = g[(N+1)/2][1];
    }

    // for(int i=1; i<=N; i++) cntR += checkR(i);
    // for(int i=1; i<=M; i++) cntR += checkC(i);
    // if (cntR != R || cntC != C) fail();

    for (int i = 1; i<=N; i++) {
        for (int j = 1; j<= M; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }

    return 0;
}