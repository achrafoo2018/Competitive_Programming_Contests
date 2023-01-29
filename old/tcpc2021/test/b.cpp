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
	freopen("wave.in", "r",stdin);
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll ans = -1e6;
		if(s.size() == 1)
			cout << 1 << endl;
		else{
			ll r = 0, i=0;
			while(i+1 < s.size()){
				r++;
				if(s[i] == s[i+1]){
					ans = max(ans, r);
					r = 0;
				}
				i++;
			}
			if(s[i] != s[i+1])
				r++;
			ans = max(ans, r);
			cout << ans << endl;
		}
	}
}


int main(){
	fastio;
	solve();
	return 0;
}
