#include <bits/stdc++.h>
using namespace std;

int T;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;

    while (T--) {
        char grid[3][3];

        bool found = false;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cin >> grid[row][col];
            }
        }

        for (int row = 0; row < 3; row++) {
            if (!found && grid[row][0] == grid[row][1] && grid[row][0] == grid[row][2] && grid[row][1] == grid[row][2] && grid[row][2] != '.') {
                cout << grid[row][1] << endl;
                found = true;
            } 
        }

        for (int col = 0; col < 3; col++) {
            if (!found && grid[0][col] == grid[1][col] && grid[0][col] == grid[2][col] && grid[2][col] == grid[1][col] && grid[1][col] != '.') {
                cout << grid[0][col] << endl;
                found = true;
            } 
        }

        if (!found && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[1][1] == grid[2][2] && grid[1][1] != '.' || !found && grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2] && grid[1][1] == grid[0][2] && grid[1][1] != '.') {
            cout << grid[1][1] << endl;
            found = true;
        }

        if (!found) cout << "DRAW" << endl;

    }
}