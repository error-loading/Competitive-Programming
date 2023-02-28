#include <iostream>
using namespace std;

long long m; int n;
long long psa[500001];

int main() {
    cin >> n >> m;
    psa[0]=0;
    for (int i = 1; i<n+1;i++) {
        cin>>psa[i];
    }
    for (int i = 1; i<n+1;i++) {
        psa[i] += psa[i-1];
    }
    if (psa[n] < m) {
        cout << -1;
        return (0);
    }

    int low = 1; int high = 1;
    int minimum = n;
    while(low!=n+1 && high<n+2){
        if (psa[high]-psa[low-1] < m) {
            high+=1;
        } else if (psa[high]-psa[low-1] >= m) {
            minimum = min(minimum, high-low+1);
            low+=1;
        }
    }
    cout << minimum;
    return(0);
}