#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		ll c, m, x;
		cin >> c >> m >> x;
		if(c == 0 || m == 0)
			cout << 0 << endl;
		else{
			ll res = (c+m+x) / 3;
			cout << ((min(c, m) >= res) ? res : min(c, m)) << endl;
		}
	}	
	return 0;
}
