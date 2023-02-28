// https://dmoj.ca/problem/dmopc16c2p4
// DMOPC '16 Contest 2 P4 - Zeros

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

long long getZeros(long long num) {
    long long total = 0;
    for (long long i = 5; num / i >= 1; i *= 5)
        total += num / i;
    return total;
}



int main() {
    long long low,high,mid,upper,lower;
    int a, b;
    cin >> a >> b;
    low = 1;
    high = 50000000000;
    while (true) {
        mid = (high+low)/2;
        if (high == low) {
            lower = low;
            break;
        }
        if (getZeros(mid) >= a) {
            high = mid;
        }
        else if (getZeros(mid) < a) {
            low = mid+1;
        }
    }
    low = 1; high = 50000000000;
    while (true) {
        mid = (high+low+1)/2;
        if (high == low) {
            upper = low;
            break;
        }
        if (getZeros(mid) <= b) {
            low = mid;
        }
        else if (getZeros(mid) > b) {
            high = mid-1;
        }
    }
    cout << upper-lower+1;
    return(0);
}