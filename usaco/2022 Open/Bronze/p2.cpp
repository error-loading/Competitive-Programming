// http://usaco.org/index.php?page=viewproblem2&cpid=1228
#include <bits/stdc++.h>
using namespace std;

int N, P, small = 0, big = 1e9, cnt = 0;
char L;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> L >> P;
        if (L == 'G' && P >= small && P <= big) {
            small = P;
        }

        else if (L == 'L' && P >= small && P <= big) {
            big = P;
        } else {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}