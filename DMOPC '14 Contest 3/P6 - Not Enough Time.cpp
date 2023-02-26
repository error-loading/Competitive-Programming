// https://dmoj.ca/problem/dmopc14c3p6
// DMOPC '14 Contest 3 P6 - Not Enough Time!

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
int N, W, dp[10002];
int main(){
    cin >> N >> W;
    for(int i=1, v1, w1, v2, w2, v3, w3; i<=N; i++){
        cin >> w1 >> v1 >> w2 >> v2 >> w3 >> v3;
        for(int j=W; j>=w1; j--){
            if(j >= w1) dp[j] = max(dp[j], dp[j-w1] + v1);
            if(j >= w2) dp[j] = max(dp[j], dp[j-w2] + v2);
            if(j >= w3) dp[j] = max(dp[j], dp[j-w3] + v3);
        }
    }
    cout << dp[W] << endl;
}