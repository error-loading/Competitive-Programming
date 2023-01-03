// https://dmoj.ca/problem/macs1p1
// Max's Anger Contest Series 1 P1 - Hunger Bar

#include <iostream>
#define ll long long

using namespace std;

ll h, a, s;
ll mini = 1000000000000;

int main() {
    cin >> h >> a>> s;
    mini = min(h,a) - s;
    if (mini>0) {
        cout << mini << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;

}