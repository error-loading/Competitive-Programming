#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

const int MAXSZ = 3e5 + 5;
int N, x;
vector<int> arr;
int leftRightBig[MAXSZ];
int leftRightSmall[MAXSZ];
int rightLeftBig[MAXSZ];
int rightLeftSmall[MAXSZ];
stack<pii> stk;
stack<pii> stk2;
stack<pii> stk3;
stack<pii> stk4;

signed main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        arr.push_back(x);
    }

    int ans = 0;
    stk.push({1000000005, -1});
    stk3.push({1000000005, N});
    stk2.push({-1000000005, -1});
    stk4.push({-1000000005, N});
    for (int i = 0; i < N; ++i) {
        while (!stk.empty() && arr[i] >=  stk.top().first) stk.pop();
        leftRightBig[i] = stk.top().second + 1;
        stk.push({arr[i], i});
    }
  
    for (int i = N - 1; i > -1; --i) {
        while (!stk3.empty() && arr[i] >  stk3.top().first) stk3.pop();
        rightLeftBig[i] = stk3.top().second - 1;
        stk3.push({arr[i], i});
    }
  
    for (int i = 0; i < N; ++i) {
        while (!stk2.empty() && arr[i] <=  stk2.top().first) stk2.pop();
        leftRightSmall[i] = stk2.top().second + 1;
        stk2.push({arr[i], i});
    }
  
    for (int i = N - 1; i > -1; --i) {
        while (!stk4.empty() && arr[i] < stk4.top().first) stk4.pop();
        rightLeftSmall[i] = stk4.top().second - 1;
        stk4.push({arr[i], i});
    }

    for (int i = 0; i < N; ++i) {
      ans += arr[i] * (rightLeftBig[i] - i + 1) * (i + 1 - leftRightBig[i]) - arr[i] * (rightLeftSmall[i] - i + 1) * (i + 1 - leftRightSmall[i]);
    }

    cout << ans << endl;

  


}