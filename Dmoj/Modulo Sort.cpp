#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, x;
vector<int> arr;

bool cmp(int f, int s) {
    if (f % K < s % K) return true;
    else if (f % K == s % K && f < s) return true;
    else return false; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (auto e : arr) {
        cout << e << " ";
    }
    cout << "\n";

}