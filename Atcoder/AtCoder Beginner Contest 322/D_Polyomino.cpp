// i hate this question...

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (n); i++)


void Rotate(vector<string> & s) {
    vector<string> w = s;
    rep(i, 4) rep(j, 4) w[3 - j][i] = s[i][j];
    s = w;

}

bool in_range(int x, int y) {
    if (x < 0 || x >= 4 || y < 0 || y >= 4) return false;
    return true;
}

bool can_put(vector<vector<int>> &board, vector<string> &pcs, int move_x, int move_y)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (pcs[i][j] == '#') {
                int dx = i + move_x;
                int dy = j + move_y;

                if (!in_range(dx, dy)) return false;
                if (board[dx][dy] == 1) return false;
                board[dx][dy] = 1;
            }
        }
    }

    return true;
}

bool check_grid(vector<vector<int>> board) {
    bool num = 1;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            num &= board[i][j];
        }
    }

    return num;
}

void dfs(int pc_num, vector<vector<int>> &board, vector<vector<string>> &pcs) {
    if (pc_num == 3) {
        bool full = check_grid(board);
        if (full) {cout << "Yes" << endl; exit(0);}
        return;
    }

    for (int move_x = -3; move_x <= 3; move_x++) {
        for (int move_y = -3; move_y <= 3; move_y++) {
            auto temp_board = board;
            if (can_put(temp_board, pcs[pc_num], move_x, move_y)) dfs(pc_num+1, temp_board, pcs);
        }
    }


}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<vector<string>> pc(3);

    for (int i = 0; i < pc.size(); ++i) {
        pc[i].resize(4);
        for (auto &s : pc[i]) cin >> s;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            vector<vector<int>> board(4, vector<int>(4, 0));

            dfs(0, board, pc);

            Rotate(pc[2]);
        }
        Rotate(pc[1]);
    }

    cout << "No" << endl;
    return 0;
}