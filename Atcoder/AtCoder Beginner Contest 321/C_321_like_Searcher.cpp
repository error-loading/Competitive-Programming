#include <iostream>

using namespace std;

bool is_321_like(int x) {
    int prev_digit = 10; // Initialize prev_digit to a value greater than 9
    while (x > 0) {
        int digit = x % 10;
        if (digit >= prev_digit) {
            return false;
        }
        prev_digit = digit;
        x /= 10;
    }
    return true;
}

int count_321_like(int value) {
    int count = 0;
    for (int i = 1; i <= value; i++) {
        if (is_321_like(i)) {
            count++;
        }
    }
    return count;
}

int find_kth_321_like(int K) {
    int left = 1;
    int right = 2 * K; // Adjust the upper bound as needed

    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = count_321_like(mid);

        if (count < K) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    int K;
    cin >> K;

    int ans = find_kth_321_like(K);

    cout << ans << endl;

    return 0;
}
