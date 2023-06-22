#include <iostream>
using namespace std;

const int MM = 1e6 + 5;
int N, arr[MM], ind, odd_ind;

bool check_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;


    for (int i = 2; i <= N; i++) {
        arr[i / 2] = i;
        ind = i / 2;
    }

    for (int i = 1; i <= N; i++) {
        if (!check_prime(arr[ind] + i)) {
            arr[ind + 1] = i;
        }
    }

    odd_ind = ind + 2;

    for (int i = 1; i <= N; i+= 2) {
        if (i != arr[ind]) {
            arr[odd_ind] = i;
            odd_ind += 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}