// https://dmoj.ca/problem/ccc22s1
// CCC '22 S1 - Good Fours and Good Fives

#include <iostream>
#include <cmath>
using namespace std;

int n;

int main() {
    cin >> n;
    int num = floor(n/4);

    int ttl = 0;

    for (int i = 0; i<= num; i++) {
        int some = 4*i;
        if ((n - some) % 5 == 0) {
            ttl+=1;
        }
    }
    cout << ttl;
}