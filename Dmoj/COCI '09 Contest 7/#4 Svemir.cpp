// https://dmoj.ca/problem/coci09c7p4
// COCI '09 Contest 7 #4 Svemir

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



typedef array<int, 3> E;
typedef array<int, 4> E2;
const int MM=1e5 + 3;
int N, x, y, z, p[MM], last; vector<E2> adj; vector<E> edge; vector<E2> adj2; vector<E2> adj3;

int find_set(int d) {
    if (d!= p[d]) p[d] = find_set(p[d]);
    return p[d];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int counter = 0;
    cin >> N;
    for (int i = 1; i<=N; i++) p[i] = i;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        adj.push_back({x, y, z, i});
        adj2.push_back({y, x, z, i});
        adj3.push_back({z, y, z, i});
    }
    sort(adj.begin(), adj.end());
    sort(adj2.begin(), adj2.end());
    sort(adj3.begin(), adj3.end());

    for (int i = 1; i < N; i++) {
        edge.push_back({min(abs(adj[i][0] - adj[i-1][0]), min(abs(adj[i][1] - adj[i-1][1]), abs(adj[i][2] - adj[i-1][2]))), adj[i-1][3], adj[i][3]});
        edge.push_back({min(abs(adj2[i][0] - adj2[i-1][0]), min(abs(adj2[i][1] - adj2[i-1][1]), abs(adj2[i][2] - adj2[i-1][2]))), adj2[i-1][3], adj2[i][3]});
        edge.push_back({min(abs(adj3[i][0] - adj3[i-1][0]), min(abs(adj3[i][1] - adj3[i-1][1]), abs(adj3[i][2] - adj3[i-1][2]))), adj3[i-1][3], adj3[i][3]});
    }

    sort(edge.begin(), edge.end());


    for (int x = 0; x < edge.size(); x++){
        int fu=find_set(edge[x][1]), fv=find_set(edge[x][2]);
        if (fu!=fv){
            p[fu] = fv;
            counter += edge[x][0];
        }
    }
    cout << counter << endl;

    return 0;
}