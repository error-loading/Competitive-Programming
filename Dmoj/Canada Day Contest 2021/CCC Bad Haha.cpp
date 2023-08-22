#include <bits/stdc++.h>
using namespace std;

#define int long long

int T, K;
string N;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;
        cin >> K;
        vector<int> arr;

        int i = 0;

        while (arr.size() < K) {
            if (i > N.size()) break;
            if ((char)N[i] - '0' > (char)N[i + 1] - '0') {
                arr.push_back((char)N[i] - '0');
                N.erase(N.begin()+i);

                if (i - 1 >= 0) i--;
            } else {
                i++;
            }
        }

        cout << N;
        sort(arr.begin(), arr.end());
        for (auto e : arr) cout << e;
        cout << endl;
    }

    return 0;
}