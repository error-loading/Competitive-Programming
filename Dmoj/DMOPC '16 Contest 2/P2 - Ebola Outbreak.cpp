#include <iostream>
#include <vector>
using namespace std;

const int MM = 1e5 + 5;
int N, M, K;

int dsu[MM];
int arr[MM];

int find(int a) {
    if (dsu[a] != a) return dsu[a] = find(dsu[a]);
    return dsu[a];
}

void merge(int a, int b) {
    if (b == 1) swap(a, b);
    dsu[b] = a;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

//    create parents
    for (int i = 1; i<= N; i++) {
        dsu[i] = i;
    }

    while (M--) {
        cin >> K >> arr[1];
        int fir = find(arr[1]);

        for (int i = 2; i<= K; i++) {
            cin >> arr[i];
            int sec = find(arr[i]);
            if (fir != sec) {
                merge(fir, sec);
            }
        }
    }
    vector<int> things;
    for (int i = 1; i <= N; i++) {
        int par = find(i);
        if (par == 1) things.push_back(i);
    }

    cout << things.size() << endl;

    for (auto e : things) cout << e << " ";
}