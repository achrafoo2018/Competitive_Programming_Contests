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
	freopen("eat.in", "r",stdin);
	ll t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		if(a+b > a*b)
			cout << "Plate 1" << endl;
		else
			cout << "Plate 2" << endl;
	}
}

int main(){
	fastio;
	solve();
	return 0;
}
