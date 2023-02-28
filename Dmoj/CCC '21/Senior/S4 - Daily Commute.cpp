// https://dmoj.ca/problem/ccc21s4
// CCC '21 S4 - Daily Commute

/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
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
#include <stdlib.h>
#include <assert.h>

using namespace std;
const int MM = 2e5+5;
int N, W, D, walk[MM], train[MM], route[MM]; vector<int> adj[MM]; bool vis[MM]; queue<int> q;
struct node { int l, r, v;} seg[MM*3];
void build(int l, int r, int rt){
    seg[rt].l = l; seg[rt].r = r;
    if(l == r) { seg[rt].v = walk[l] + train[l]; return; }
    int mid = (l + r)/2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
    seg[rt].v = min(seg[2*rt].v, seg[2*rt+1].v);
}
void upd(int pos, int val, int rt){
    if(seg[rt].l == seg[rt].r) { seg[rt].v = val;  return;}
    int mid = (seg[rt].l + seg[rt].r)/2;
    pos <= mid? upd(pos, val, 2*rt) : upd(pos, val, 2*rt+1);
    seg[rt].v = min(seg[2*rt].v, seg[2*rt+1].v);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W >> D;
    for(int i=1, a, b; i<=W; i++){
        cin >> a >> b;  adj[b].push_back(a);
    }
    memset(walk, 0x3f, sizeof(walk));
    walk[N] = 0;  vis[N] = 1;  q.push(N);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(!vis[v]) { vis[v]=1; q.push(v); walk[v]=walk[u]+1; }
        }
    }
    for(int i=1; i<=N; i++) {
        cin >> route[i]; train[route[i]] = i - 1;
    }
    build(1, N, 1);
    for(int i=1, x, y; i<=D; i++){
        cin >> x >> y;    int px = route[x], py = route[y];
        swap(train[px], train[py]); swap(route[x], route[y]);
        upd(px, walk[px]+train[px], 1);  upd(py, walk[py]+train[py], 1);
        cout << seg[1].v << "\n";
    }
}