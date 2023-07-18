#include <bits/stdc++.h>
using namespace std;

int T, n, d, h, y;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout.precision(10); cout.setf(ios::fixed);
    cin >> T;

    while (T--) {
        cin >> n >> d >> h;

        long double area = (long double)d * h / 2.0;

        vector<int> height(n);
        for(int i = 0; i < n; i++){
            cin >> height[i];
        }

        for (int i = 0; i + 1 < n; ++i) {
            if (height[i + 1] >= height[i] + h) area += (long double)d * h / 2.0;
            else{
                long double d2 = (long double)d * (height[i] + h - height[i + 1]) / h;
                long double nh = height[i + 1] - height[i];
                area += (d + d2) / 2.0 * nh;
            }
        }


        cout << area << endl;

    }
}