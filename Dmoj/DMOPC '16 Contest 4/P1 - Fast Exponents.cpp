#include <iostream>
using namespace std;

int N, x;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> x;

        if (!(x & (x - 1))) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }
}