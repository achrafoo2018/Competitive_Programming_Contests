#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll q = 1;
		ll res = 0;
		ll j=1;
		for(ll i=8; q < n*n; i+=8){
			res += i*j;
			j++;
			q += i;
		}
		cout << res << endl;
	}	
	return 0;
}
