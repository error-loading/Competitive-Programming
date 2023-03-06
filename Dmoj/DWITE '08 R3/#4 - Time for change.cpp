// https://dmoj.ca/problem/dwite08c3p4
// DWITE '08 R3 #4 - Time for change

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
#include <iomanip>
#include <assert.h>

using namespace std;

int main() {
    for (int _ = 0; _<5; _++) {
        int m, n, coins[15], dp[105];
        cin >> m >> n;
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i< n; i++) {
            cin >> coins[i];
        }
        dp[0] = 0;
        for (int i = 0; i<= m; i++) {
            for (int j = 0; j<n;j++) {
                if (i + coins[j] <= m) {
                    dp[i+coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
                }
            }
        }
        cout << dp[m] << endl;
    }

    return 0;
}