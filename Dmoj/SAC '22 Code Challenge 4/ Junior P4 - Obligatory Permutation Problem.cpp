// https://dmoj.ca/problem/sac22cc4jp4
// SAC '22 Code Challenge 4 Junior P4 - Obligatory Permutation Problem

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
#include <cmath>

using namespace std;

/* TYPES */
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define mii map<int, int>

/* UTILS */
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

const int MM = 1e5 + 5;
int n, nxt[MM], ans[MM]; ll k; bool vis[MM];
int main() {
    cin >> n >> k;
    for (int i = 1; i<=n; i++) cin >> nxt[i];
    for (int i = 1; i<=n; i++) {
        if (vis[i]) continue;
        vector<int> cycle;
        for (int cur = i; !vis[cur]; cur = nxt[cur]) {
            vis[cur] = true; cycle.push_back(cur);
        }
        int rem = k % cycle.size();
        for (int i = 1; i<=cycle.size(); i++) {
            int pos = cycle[(i+rem) % cycle.size()];
            ans[i] = cycle[pos];
        }
    }
    for (int i = 1; i<=n; i++) cout << ans[i] << " \n"[i==n];
}