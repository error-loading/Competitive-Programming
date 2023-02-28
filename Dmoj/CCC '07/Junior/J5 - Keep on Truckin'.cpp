// https://dmoj.ca/problem/ccc07j5
// CCC '07 J5 - Keep on Truckin'

#include <iostream>
#include <vector>
using namespace std;

vector<long long> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int a, b, m; 
int main() {
  cin >> a >> b >> m;
  for (long long i = 0; i<m; i++) {
    long long mi; cin >> mi;
    motels.push_back(mi);
  }
  sort(motels.begin(), motels.end());
  long long comb[motels.size()];
  for (long long i = 0; i< motels.size(); i++) {
    comb[i] = 0;
  }
  comb[0] = 1;
  for (long long i = 1; i<motels.size(); i++) {
    for (long long j = i-1; j>-1; j--) {
      if (motels[i] - motels[j] >= a && motels[i] - motels[j] <= b) {
        comb[i]+=comb[j];
      }
    }
  }
  cout << comb[motels.size()-1] << endl;
  return 0;
}