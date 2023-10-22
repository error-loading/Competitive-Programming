#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MM = 1025;
int ins, S, bit[MM][MM];

void update(int r, int c, int val) {
    for (int i = r; i <= S; i += (i&-i)) {
        for (int j = c; j <= S; j+= (j&-j)) {
            bit[i][j] += val;
        }
    }
}

int query(int r, int c) {
	int ret = 0;
	for(int i=r; i>0; i-=(i&-i))
		for(int j=c; j>0; j-=(j&-j))
			ret += bit[i][j];
	return ret;
}

int sum(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}
 

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> ins;

    while (ins != 3)
    {
        if (ins == 0) {
            cin >> S;
        } else if (ins == 1) {
            int x, y, a; cin >> x >> y >> a; x++, y++;
            update(x, y, a);
        } else if (ins == 2) {
            int l, b, r, t; cin >> l >> b >> r >> t; l++, b++, r++, t++;
            cout << sum(l, b, r, t) << endl;
        }

        cin >> ins;
    }
}
