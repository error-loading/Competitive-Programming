// https://dmoj.ca/problem/dpf
// Educational DP Contest AtCoder F - LCS

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
#include <unordered_set>
#include <stdlib.h>
#include <assert.h>
#include <climits>
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
//#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
#define all(x) x.begin(),x.end()
//ll min(ll a,int b) { if (a<b) return a; return b; }
//ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

const int MM = 3005;
char s[MM], t[MM];
int dp[MM][MM];
string string1, string2;

int main() {
    cin >> string1 >> string2;
    for (int i = 1; i<=string1.size(); i++) s[i] = string1[i-1];
    for (int i = 1; i<=string2.size(); i++) t[i] = string2[i-1];
    for(int i=1; i<=string1.size(); i++) {
        for(int j=1; j<=string2.size(); j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    int l = string1.size(), r = string2.size();
    string lcs = "";
    while (l and r) {
        if (s[l] == t[r]) {
            lcs = s[l] + lcs;
            l -= 1;
            r -= 1;
        } else if (dp[l][r-1] >= dp[l-1][r]) {
                r--;
        } else l--;
    }
    cout << lcs << endl;
    return 0;
}