// https://dmoj.ca/problem/ecoo21p3
// ECOO '21 P3 - Quintessential Questions
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
const int MM = 2e5 + 5;

int N, M, K, A, B, C;


pii arr[MM];

int main() {
    cin >> N >> M >> K;

    for (int i = 1; i<=N; i++) {
        arr[i] = {-1, -1};
    }

    while (K--) {
        cin >> A >> B >> C;
        if (arr[B].first < C) {
            arr[B] = {C, B};
        }
    }

    for (int i = 1; i<=N; i++) {
        cout << arr[i].second << " ";
    }

}