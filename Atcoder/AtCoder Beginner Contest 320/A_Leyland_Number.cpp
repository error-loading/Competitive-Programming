#include <bits/stdc++.h>
using namespace std;

#define int long long

int A, B;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;

    cout << (int)pow(A, B) + (int)pow(B, A) << endl;
}