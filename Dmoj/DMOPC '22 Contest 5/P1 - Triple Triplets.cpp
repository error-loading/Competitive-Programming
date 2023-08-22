#include <bits/stdc++.h>

using namespace std;

#define int long long

int N, i = 1;
long long tot = 0;

vector<int> myArr;

long long query(int num) {
    return (num)*(num-1)/2;
}

signed main() {

    cin >> N;
    
    //i is number of 2s in list
    for (i = 1; N-(i*2) >= 0; i++) {
        if (i * query(N-(i*2)) > tot) {
            tot = i * query(N-(i*2));
        }
    }

    cout << tot;
    return 0;
}