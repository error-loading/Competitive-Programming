// https://dmoj.ca/problem/dp1p3
// Longest Increasing Subsequence

#include <iostream>
using namespace std;


int main() {
  int n; cin >> n;
  int arr[n];
  int dp[n];
  for (int i = 0; i<n; i++){
    dp[i] = 1;
    cin >> arr[i];
  }
  

  for (int i = 0; i<n; i++){
    for (int j = 0; j<i; j++) {
      if (arr[j] < arr[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }

  int greatest = 0;
  for (int i = 0; i<n; i++){
    greatest = max(greatest, dp[i]);
  }
  cout << greatest;
  
  return 0;
}