// https://dmoj.ca/problem/vmss7wc16c5p4
// VM7WC '16 #5 Silver - Jayden Eats Chocolate

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

const int MM = 1e5+3;
int n, w, dp[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fill(dp, dp+MM, -1e9);
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        cin >> w;
        for (int j = w; j <= n; j++) {
            dp[j] = max(dp[j], dp[j-w]+1);
        }
    }
    cout << dp[n] << "\n";