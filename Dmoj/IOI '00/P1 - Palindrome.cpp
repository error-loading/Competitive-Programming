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

int dp[2][5005];
int n;
string string1, string2;

int main() {
    cin >> n;
    cin >> string1;
    string2 = string1;
    reverse(string2.begin(), string2.end());

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            if (i%2 == 0) {
                dp[0][j] = max(dp[1][j], dp[0][j-1]);
                if(string1[i-1] == string2[j-1]) dp[0][j] = max(dp[0][j], dp[1][j-1] + 1);
            } else {
                dp[1][j] = max(dp[0][j], dp[1][j-1]);
                if(string1[i-1] == string2[j-1]) dp[1][j] = max(dp[1][j], dp[0][j-1] + 1);
            }
        }
    }
    if (n%2) cout << n - dp[1][n];
    else cout << n - dp[0][n];
}