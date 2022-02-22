#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll l, r;
		cin >> l >> r;
		if(l == r)
			cout << 0 << endl;
		else{
			if(l <= (r/2 + 1))
				cout << r%(r/2+1) << endl;
			else
				cout << r%l << endl;
		}
	}	
	return 0;
}
