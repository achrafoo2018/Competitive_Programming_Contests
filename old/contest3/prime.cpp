#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isPrime(int n){
	for(int i=2; i < (int) sqrt(n) + 1; ++i){
		if(n % i == 0)
			return false;
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int res = 0;
		for(int i=2; i <= n;i++){
			if(isPrime(i))
				res++;
		}
		cout << res << endl;
	}	
	return 0;
}
