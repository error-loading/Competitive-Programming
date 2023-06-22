#include <iostream>
#include <cmath>
using namespace std;

const int MM = 55;
int N, Q = 5;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (Q--) {
        cin >> N;
        int arr[MM], avg = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            avg += arr[i];
        }

        avg /= N;

        int rest = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] != avg) rest += abs(arr[i] - avg);
        }

        cout << rest / 2 << endl;

    }
}