#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 55;
char moves[MAXSZ], friends[MAXSZ][MAXSZ];
int R, N, score, pos;
string sven, op;

unordered_map<char, char> symb {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R;

    cin >> sven;
    for (int i = 0; i < R; ++i) moves[i] = sven[i];
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> op;
        for (int j = 0; j < R; ++j) {
            friends[i][j] = op[j];

            if (symb[friends[i][j]] == moves[j]) score+= 2;
            else if (friends[i][j] == moves[j]) score++;
        }
    }

    for (int j = 0; j < R; ++j) {
        int rock = 0;
        int paper = 0;
        int scissors = 0;
        for (int i = 0; i < N; ++i) {
            if (symb[friends[i][j]] == 'R') rock += 2;
            if (symb[friends[i][j]] == 'S') scissors += 2;
            if (symb[friends[i][j]] == 'P') paper += 2;

            if (friends[i][j] == 'R') rock++;
            if (friends[i][j] == 'S') scissors++;
            if (friends[i][j] == 'P') paper++;

        }

        pos += max(rock, max(paper, scissors));

    }

    cout << score << endl;
    cout << pos << endl;


}