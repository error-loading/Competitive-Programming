// https://dmoj.ca/problem/coci12c3p4
// COCI '12 Contest 3 #4 Aerodrom

#include <iostream>

using namespace std;

int n,m,desks[100000],t;

long long time(long long test){
    long long ans = 0;
    for (int i = 0; i < n; i ++){
        ans += test/desks[i];
    }
    return ans;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        cin >> desks[i];
    }
    long long lo = 1, hi = 1e18, mid;

    while (hi > lo){
        mid = (lo+hi)/2;
        if (time(mid) >= m){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout << lo;

    return 0;
}