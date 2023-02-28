// https://dmoj.ca/problem/dpb
// Educational DP Contest AtCoder B - Frog 2

#include <iostream>
using namespace std;
int costs[100000];
int heights[100000];

int main(){
    int n,k,a;
    cin >> n >> k;
    for (int i = 0; i < n; i ++){
        cin >> a;
        heights[i] = a;
    }
    if (k >= n - 1){
        cout << abs(heights[0]-heights[n-1]);
    } else {
        for (int i = 0; i < k; i ++){
            costs[i] = abs(heights[0]-heights[i]);
        }
        for (int i = k; i < n; i ++){
            int small = costs[i-1] + abs(heights[i]-heights[i-1]);
            for (int j = 1; j < k; j ++){
                if (small > costs[i-j-1] + abs(heights[i]-heights[i-j-1])){
                    small = costs[i-j-1] + abs(heights[i]-heights[i-j-1]);
                }
            }
            costs[i] = small;
        }
        cout << costs[n-1];
    }
    
    return 0;
}