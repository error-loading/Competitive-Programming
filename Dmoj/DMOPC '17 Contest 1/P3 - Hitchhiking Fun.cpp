// https://dmoj.ca/problem/dmopc17c1p3
// DMOPC '17 Contest 1 P3 - Hitchhiking Fun

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
#include <climits>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/* TYPES */
#define ll long long
#define pii pair<int, int>
#define tii tuple<int, int, int>
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

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x/= 10;
    }while(x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
    T n=0,s=1;
    char p=getchar();
    if(p=='-')
        s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-')
        p=getchar();
    if(p=='-')
        s=-1,p=getchar();
    while(p>='0'&&p<='9') {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=getchar();
    }

    return n*s;
}

int max1=INT_MAX;

int n, m, a, b, t;
vector<pii> adj[100005];
priority_queue<tii, vector<tii>, greater<tii>> pq;
pii dist[100005];

int main() {
    cin >> n >> m;
    for (int i = 0; i< m; i++) {
        cin >> a >> b >> t;
        adj[a].emplace_back(t, b);
        adj[b].emplace_back(t, a);
    }
    for (int i = 0; i<100005; i++) dist[i].first = max1;
    dist[1].first = 0; dist[1].second = 0;
    pq.emplace(0, 0, 1);
    while (!pq.empty()) {
        auto [dis, badRoads, node1] = pq.top(); pq.pop();
        for (auto [cost, node2]: adj[node1]) {
            if (dist[node2].first > cost + dis) {
                dist[node2].first = cost + dis;
                dist[node2].second = dist[node1].second + 1;
                pq.emplace(dist[node2].first, dist[node2].second, node2);
            } else if (dist[node2].first == cost + dis && dist[node2].second > dist[node1].second + 1) {
                dist[node2].second = dist[node1].second + 1;
                pq.emplace(dist[node2].first, dist[node2].second, node2);
            }
        }
    }
    if (dist[n].first == max1) cout << -1 << endl;
    else cout << dist[n].first << " " << dist[n].second << endl;

    return 0;
}