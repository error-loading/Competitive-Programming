#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int MAXSZ = 255;
int W, H, N, psa[MAXSZ][MAXSZ];
 
int f(int a, int b, int c, int d)
{
    // cout << a << " " << b << " " << c << " " << d << endl;
    if (a < 0 || a > H || c < 0 || c > H || b < 0 || b > W || d < 0 || d > W || a > c || b > d)
    {
        return 0;
    }
 
    // cout << psa[c][d] << " " << psa[a - 1][d] << " " << psa[c][b - 1] << " " << psa[a - 1][b - 1] << endl;
    return (psa[c][d] - psa[a - 1][d] - psa[c][b - 1] + psa[a - 1][b - 1]);
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> W >> H >> N;
 
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> psa[i][j];
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
 
    int best = -1;
 
    for (int width = 1; width <= min(N, H); ++width)
    {
        for (int i = 1; i <= H; ++i)
        {
            for (int j = 1; j <= W; ++j)
            {
                best = max(best, f(i, j, min(H,i + width - 1), min(W,j + N / width - 1)));
            }
        }
    }
 
    cout << best << endl;
 
    return 0;
}