// https://dmoj.ca/problem/seed3
// The Cosmic Era P3 - Battle Positions

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

int i; int n; int j;

int psa[100005];

int main() {
    cin>> i >> n >> j;
    int xi; int xf; int k;
    for (int itr =0; itr<j; itr++) {
        cin >> xi >> xf >> k;
        psa[xi-1] +=k;
        psa[xf] -=k;
    }

    for (int itr = 0; itr < i; itr++){
        psa[itr] += psa[itr-1];
    }


    int ttl = 0;

    for (int a = 0; a<i; a++) {
        if (psa[a] < n){
            ttl+=1;
        }
    }
    cout << ttl;
    return(0);
}