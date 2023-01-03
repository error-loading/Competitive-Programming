// https://dmoj.ca/problem/cpc19c1p2
// CPC '19 Contest 1 P2 - Luggage

#include <iostream>
using namespace std;

int main() {
  int n; int k;
  cin >> n >> k;
  int arr[n];
  for (int i =0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr,arr+n);
  int minimum = 0;
  int l=0;int r=0;
  while(r!=n && l!=n) {
    if(arr[r]-arr[l] <=k) {
      minimum = max(minimum,r-l+1);
      r++;
    } else if (arr[r]-arr[l] >k) {
      l++;
    }
  }
  cout << minimum;
  return 0;
}