// https://dmoj.ca/problem/acc3p1
// Another Contest 3 Problem 1 - Diverse Arrays

#include <iostream>

using namespace std;

int v[1000000];
int main(){
    
    int n,k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    memset(v,0,sizeof(v));

    int right = 0;
    int left = 0;

    long long ans = 0;
    int size = 0;
    while (left != n && right != n+1){
        while (size < k && right != n){
            if (v[arr[right]-1] == 0){
                size ++;
                v[arr[right]-1] = 1;
            } else {
                v[arr[right]-1] ++;
            }
            right ++;
        }
        if (size == k){
            ans += n-right+1;
        }
        v[arr[left]-1] --;
        if (v[arr[left]-1] == 0){
            size --;
        }
        left ++;
    }
    cout << ans << "\n";

    return 0;
}