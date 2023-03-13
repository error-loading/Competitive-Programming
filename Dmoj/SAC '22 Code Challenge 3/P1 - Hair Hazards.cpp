// https://dmoj.ca/problem/sac22cc3p1
// SAC '22 Code Challenge 3 P1 - Hair Hazards

#include <iostream>

using namespace std;

int h, s, q;

int main () {
	cin >> h >> s >> q;
	for (int i = 0; i<q; ++i) {
		h-=s; cout << h << endl;
	}
	return 0;
}