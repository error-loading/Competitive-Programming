// https://dmoj.ca/problem/ccc17j1
// CCC '17 J1 - Quadrant Selection

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

int x, y;

int main() {
    cin >> x >> y;
    if (x > 0 and y > 0) cout << 1;
    else if (x<0 and y > 0) cout << 2;
    else if (x<0 and y < 0) cout << 3;
    else cout << 4;
    return 0;
}