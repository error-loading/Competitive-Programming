// https://dmoj.ca/problem/acmtryouts0a
// ACM U of T Tryouts C0 A - Max Flow

/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
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
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main() {
  int t; int n;
  cin >> t;
  for (int i = 0; i<t; i++) {
    cin >> n;
    int great = 0;
    for (int j = 0; j<n; j++) {
      int some; cin >> some;
      if (some > great) {
        great = some;
      }
    }
    cout << great << endl;
  }
}