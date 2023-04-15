// https://dmoj.ca/problem/ccc16s4
// CCC '16 S4 - Combining Riceballs

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


ll n, arr[3005];
ll psa[3005];
ll dp[3005][3005];
int main() {
    cin >> n;
    int ans = 0;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i<=n; i++) {cin >> arr[i]; psa[i] = arr[i]; psa[i]+=psa[i-1]; ans = max(ans, arr[i]); dp[i][i] = 1;};
    for (int i = 1; i<n; i++) {
        for (int l = 1, r = i+l; r<=n; l++, r++) {

            if (arr[l] == arr[r] && r - l == 1) dp[l][r] = 1;
            for (int k = l+1; k<=r; k++) {
                if (dp[l][k-1] && dp[k][r] && psa[k-1] - psa[l-1] == psa[r] - psa[k-1]) dp[l][r] = 1;
                for (int b = k+1; b<=r; b++) {
                    if (dp[k][b-1] && dp[l][k-1] && dp[b][r]) {
                        if (psa[k-1] - psa[l-1] == psa[r] - psa[b-1]) dp[l][r] = 1;
                    }

                }

            }
        }
    }

    for (int l = 1; l<= n; l++) {
        for (int r = 1; r<=n; r++) {
            int sum = 0;
            for (int i = l; i<=r; i++) {
                sum += arr[i];
            }
            sum *= dp[l][r];
            ans = max(sum, ans);
        }
    }

    cout << ans;

}