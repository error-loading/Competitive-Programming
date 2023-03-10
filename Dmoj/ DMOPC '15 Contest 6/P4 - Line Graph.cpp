// https://dmoj.ca/problem/dmopc15c6p4
// DMOPC '15 Contest 6 P4 - Line Graph

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

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

using namespace std;
vector<int> disj(100001, -1);
struct E { int u, v, w; };
bool cmp(E a, E b){ return a.w<b.w;}
int findset (int a){
    if (disj[a] == a) return a;
    else return disj[a] = findset(disj[a]);
}
void uni (int a, int b){
    int fa=findset(a), fb=findset(b);
    if(fa!=fb) disj[fb] = fa;
}
int main(){
    int counter = 0;
    vector<E> values;
    int n, k;
    cin >> n >> k;
    int in;
    for (int x = 0; x < n; x++){
        disj[x] = x;
    }
    for (int x = 0; x < n-k; x++){
        uni(x, x+k);
    }
    for (int x = 0; x < n-1; x++){
        cin >> in;
        values.push_back(E{x, x+1, in});
    }
    sort(values.begin(), values.end(), cmp);
    for (int x = 0, cnt=0; x < values.size(); x++){
        int fu=findset(values[x].u), fv=findset(values[x].v);
        if (fu!=fv){
            uni(fu, fv);  cnt++;
            counter += values[x].w;
            if(cnt == k-1) break;
        }
    }
    cout << counter << endl;
}