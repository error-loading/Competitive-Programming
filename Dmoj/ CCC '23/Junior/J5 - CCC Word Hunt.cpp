#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 100;

string word;
int row, col;
// row, col
char grid[MAXSZ][MAXSZ];

pair<int, int>  moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int ttl = 0;

void solve_sub1(int moveX, int moveY, int r, int c, int ind, bool turn) {
    if (c >= col || c < 0 || r >= row || r < 0 || grid[r][c] != word[ind]) return;

    if (ind == word.size() - 1) {
        ttl++;
        return;
    }

    solve_sub1(moveX, moveY, r + moveX, c + moveY, ind+1, turn);

    if (ind > 0 && !turn) {
        solve_sub1(-moveY, moveX, r - moveY, c + moveX, ind+1, !turn);
        solve_sub1(moveY, -moveX, r + moveY, c - moveX, ind+1, !turn);
    }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> word;
    cin >> row >> col;

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            cin >> grid[r][c];
        }
    }

    for (auto [moveX, moveY] : moves) {
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                solve_sub1(moveX, moveY, r, c, 0, false);
            }
        }
    }

    cout << ttl << endl;

    return 0;
}