#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	cout << fixed;
	cout << setprecision(9);
	while(t--){
		int n;
		long long s = 0, ma = INT_MIN, j;
		cin >> n;
		for(int i=0; i < n; i++){
			cin >> j;
			if(j > ma)
				ma = j;
			s += j;
		}
		s -= ma;
		cout << (double)ma + ((double)s / (double)(n - 1)) << endl; 
	}	
	return 0;
}
