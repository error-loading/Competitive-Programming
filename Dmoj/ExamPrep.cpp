// https://dmoj.ca/problem/examprep
// Exam Prep

#include <iostream>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int n, q, p[MM], sz[MM]; ll val[MM];
int find_set(int d){
    return d==p[d]? p[d]: p[d]=find_set(p[d]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        p[i] = i;  sz[i] = 1;  cin >> val[i];
    }
    for(int i=1, op, x, y; i<=q; i++) {
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            int fx = find_set(x), fy = find_set(y);
            if(fx != fy) {
                p[fx] = fy; sz[fy] += sz[fx]; val[fy] += val[fx];
            }
        }else if(op == 2){
            cin >> x; cout << sz[find_set(x)] << "\n";
        }else {
            cin >> x; cout << val[find_set(x)] << "\n";
        }
    }
}