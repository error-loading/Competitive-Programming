// https://dmoj.ca/problem/ccc11s3
// CCC '11 S3 - Alice Through the Looking Glass

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
int T, m, x, y, pw[14];
int main(){
    pw[0] = 1;
    for(int i=1; i<=13; i++) pw[i] = pw[i-1] * 5;
    for(cin >> T; T--; ){
        cin >> m >> x >> y;
        for(int k=m; k>=1; k--){
            int side = pw[k-1], bx = x/side, by = y/side;
            if ((by==0 && 1 <= bx && bx<=3)  || (by==1 && bx==2)){
                cout << "crystal\n"; break;
            } else if(k > 1 && (by==1 && (bx == 1 || bx == 3) || (by==2 && bx == 2))){
                x = x % side;  y = y % side;
            }else {
                cout << "empty\n"; break;
            }
        }
    }
}