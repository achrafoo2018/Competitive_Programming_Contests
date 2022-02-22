#include "bits/stdc++.h"
/***************************************************/
/***************************************************/
/******************* 3ak3ek ************************/
/***************************************************/
/***************************************************/
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
	ll n;
	cin >> n;
	vll v(n+1), vu(n+1);
	for(int i=1; i <= n; i++){
		cin >> v[i];
		vu[i] = v[i];
	}
	sort(all(vu));
	for(int i=1; i <= n; i++){
		v[i] = v[i-1] + v[i];
	}
	for(int i=1; i <= n; i++){
		vu[i] = vu[i-1] + vu[i];
	}
	ll m;
	cin >> m;
	For(i, m){
		int type;
		ll l, r;
		cin >> type >> l >> r;
		if(type == 1)
			cout << v[r] - v[l-1] << endl;
		else
			cout << vu[r] - vu[l-1] << endl;
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
