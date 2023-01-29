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
	freopen("collectingofficer.in", "r", stdin);
	int t;
	string alph = "BCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i = 0, j=0;
		int ans = 1e9;
		while(i < n){
			i = j;
	 		int alpha=0, r = 0;
			while(s[i] != 'A' && i < n){
				i++;
				j = i;
			}
			if(i < n){
				alpha++;
				i++;
				r++;
			}
			else
				break;
			for(char c : alph){
				while(s[i] != c && i < n){
					i++;
					r++;
				}
				if(i < n && s[i] == c){
					alpha++;
					i++;
					r++;
				}
				else
					break;
			}
			if(alpha == 26)
				ans = min(ans, r);
			j++;
		}
		cout << ans << endl;
	}
		
}

int main(){
	fastio;
	solve();
	return 0;
}
