#include <bits/stdc++.h>
using namespace std;

#define int long long
int N;

signed main() {
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; ++i) cin >> arr[i];

    stack<int> stk;
    int last, ans = 0;

    for (int i = 1; i < N; ++i) {
      while (stk.size() > 0 && arr[i] < stk.top()) {
        stk.pop();
      }

      if (!stk.size()) {
        last = arr[i];
        stk.push(arr[i]);
        ans++;
      }
      else if (arr[i] != stk.top()) {
          stk.push(arr[i]);
          ans++;
      }


    }
    cout << ans;
}