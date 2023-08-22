#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = 4e3 + 10;
int N, T, x, y, X, Y, t;

struct Glass
{
    int x, y, X, Y, t;
} glass[MAXSZ];

set<int> x_vals;
set<int> y_vals;

map<int, int> rcomprx;
map<int, int> rcompry;

int grid[MAXSZ][MAXSZ];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y >> X >> Y >> t;
        glass[i].x = x;
        glass[i].y = y;
        glass[i].X = X;
        glass[i].Y = Y;
        glass[i].t = t;

        x_vals.insert(x);
        x_vals.insert(X);

        y_vals.insert(y);
        y_vals.insert(Y);
    }

    vector<int> comprx(x_vals.begin(), x_vals.end());
    vector<int> compry(y_vals.begin(), y_vals.end());

    for (int i = 0; i < x_vals.size(); ++i)
    {
        rcomprx[comprx[i]] = i;
    }

    for (int i = 0; i < y_vals.size(); ++i)
    {
        rcompry[compry[i]] = i;
    }

    for (int i = 0; i < N; ++i)
    {
        x = rcomprx[glass[i].x];
        y = rcompry[glass[i].y];
        X = rcomprx[glass[i].X];
        Y = rcompry[glass[i].Y];
        t = glass[i].t;


        grid[x][y] += t;
        grid[X][y] -= t;
        grid[x][Y] -= t;
        grid[X][Y] += t;
    }

    int ans = 0;




    for (int i = 1; i <= rcomprx.size(); ++i) {
        grid[i][0] += grid[i - 1][0];
    }

    for (int i = 1; i <= rcompry.size(); ++i) {
        grid[0][i] += grid[0][i - 1];
    }
    
    for (int i = 1; i <= rcomprx.size(); ++i)
    {
        for (int j = 1; j <= rcompry.size(); ++j)
        {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];

        }
    }

    for (int i = 0; i <= rcomprx.size(); ++i)
    {
        for (int j = 0; j <= rcompry.size(); ++j)
        {

            if (grid[i][j] >= T)
            {
                ans += (comprx[i + 1] - comprx[i]) * (compry[j + 1] - compry[j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}