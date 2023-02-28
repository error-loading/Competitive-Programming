// https://dmoj.ca/problem/ecoo14r1p3
// ECOO '14 R1 P3 - Word Search

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
int R, C, N; char g[40][40]; string word; bool vis[40][40];
bool fun(int idx, int r, int c, int dr, int dc){
    if(idx == word.size()) return 1;
    if(!isupper(word[idx])) return fun(idx+1, r, c, dr, dc);
    if(g[r][c] != word[idx]) return 0;
    if(fun(idx+1, r+dr, c+dc, dr, dc)) { vis[r][c] = 1; return 1; }
    return 0;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int t=5; t>0; t--){
        cin >> R >> C;  cl(g, 0); cl(vis, 0);
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++)
                cin >> g[i][j];
        }
        cin >> N; cin.ignore(1, '\n');
        for(int k=1; k<=N; k++){
            getline(cin, word);
            for(int i=1; i<=R; i++){
                for(int j=1; j<=C; j++){
                    if(g[i][j] != word[0]) continue;
                    for(int dr = -1; dr<=1; dr++){
                        for(int dc=-1; dc<=1; dc++){
                            if(dr==0 && dc == 0) continue;
                            if(fun(0, i, j, dr, dc)) {
                                goto next;
                            }
                        }
                    }
                }
            }
next:   ;
        }
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                if(!vis[i][j]) cout << g[i][j];
        cout << "\n";
    }

}