#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		int a[n];
		vector<int> b;
		for(int i=0; i < n; i++){
			cin >> a[i];
			b.push_back(a[i]);
		}
		sort(b.begin(), b.end());
		
	return 0;
}