/********   All Required Header Files ********/
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/* TYPES */
#define ll long long
#define pii pair<int, int>
#define vi vector<int>

/* UTILS */
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
const int MM = 5003;

int N, a[MM], ans[MM];
int main() {
    cin >> N;
    for (int i = 1; i<=N; i++) cin >> a[i];
    fill(ans, ans+MM, 1e9);
    for (int i = 1; i<=N; i++) {
        int val = 0;
        for (int l=i, r= i; 1<=l && r<=N; l--, r++) {
            val += abs(a[l] - a[r]);
            ans[r-l+1] = min(ans[r-l+1], val);
        }
        val = 0;
        for (int l = i, r = i+1; 1<=l && r<=N; l--, r++) {
            val += abs(a[l] - a[r]);
            ans[r-l+1] = min(ans[r-l+1], val);
        }
    }
    for (int i = 1; i<=N; i++) cout << ans[i] << " ";
}