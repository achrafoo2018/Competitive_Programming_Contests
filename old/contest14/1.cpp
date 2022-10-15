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
	map<string, ll> mp;
	For(i, n){
		ll m;
		cin >> m;
		For(j, m){
			string s;
			ll c;
			cin >> s >> c;
			if(mp.find(s) != mp.end()){
				mp[s] += c;
			}else{
				mp[s] = c;
			}
		}
	}
	cout << mp.size() << endl;
	for(auto i : mp){
		cout << i.first << " " << i.second << endl;
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}