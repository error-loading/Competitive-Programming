// https://dmoj.ca/problem/acmtryouts0a
// ACM U of T Tryouts C0 A - Max Flow

#include <iostream>
using namespace std;

int main() {
  int t; int n;
  cin >> t;
  for (int i = 0; i<t; i++) {
    cin >> n;
    int great = 0;
    for (int j = 0; j<n; j++) {
      int some; cin >> some;
      if (some > great) {
        great = some;
      }
    }
    cout << great << endl;
  }
}