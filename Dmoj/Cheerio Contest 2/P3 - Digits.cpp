#include <iostream>
using namespace std;

int X, Y, Q, a;

int solve(int ind) {
    int ttl = X + Y;
    if (ttl == ind) return 1;
    else if (ind > Y && ind <= Y + X - 1) return 0;
    else if (ind == X) return 8;
    else return 9;

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> X >> Y >> Q;

    if (X > Y) swap(X, Y);

    while (Q--) {
        cin >> a;
        cout << solve(a) << endl;
    }
}