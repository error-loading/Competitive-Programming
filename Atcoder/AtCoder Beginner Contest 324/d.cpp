#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
string S;
int ans = 0;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    sort(S.begin(), S.end());

    for (int i = 0; i * i < pow(10, N); i++) {
        string L = to_string(i * i); 
        L.resize(N, '0');
        sort(L.begin(), L.end());
        if (S == L) ans++;
    }

    cout << ans << endl;
}