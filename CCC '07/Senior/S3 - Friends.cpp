// https://dmoj.ca/problem/ccc07s3
// CCC '07 S3 - Friends

#include <iostream>
using namespace std;

const int maxn = 1e4+5;

int ppl[maxn];
bool vis[maxn];

int n,tmp1,tmp2;

int main() {
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp1>>tmp2;
		ppl[tmp1] = tmp2;
	}
	cin>>tmp1>>tmp2;
	while(!(tmp1 == 0 && tmp2==0)){
		int x = tmp1; int y =  tmp2; int dis = -1;
		
		while(x!=y && !vis[x]){
			vis[x] = true;
			x = ppl[x];
			dis++;
		}
		
		if(x==y){
			cout<<"Yes "<<dis<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		for(int i = 0; i<=n; i++){
			vis[i] = false;
		}
		cin>>tmp1>>tmp2;
	}
	return 0;
}