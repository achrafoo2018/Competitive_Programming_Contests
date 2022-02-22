#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; i++)

void solve(){
	freopen("gcd.in", "r", stdin);
	int q;
	cin >> q;
	bool one = false, first=true;
	ll gcd;
	while(q--){
		ll l, r;
		cin >> l >> r;
		if(first){
			gcd = l;
			first = false;
		}
		if(one)
			cout << 1 << endl;
		else{
			if(l != r){
				one = true;
				cout << 1 << endl;
				continue;
			}else{
				gcd = __gcd(gcd, l);
				cout << gcd << endl;
			}
		}
	}
}

int main(){
	fastio;
	solve();
	return 0;
}
