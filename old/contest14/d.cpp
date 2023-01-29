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
	int t;
	cin >> t;
	while(t--){
		int w, h, n;
		cin >> w >> h >> n;
		if(n == 1){
            cout<<"YES"<<endl;
            continue;
        }
		ll ans = 1;
        while(w % 2 == 0){
            ans *= 2;
            w = w / 2;
        }
        while(h % 2 == 0){
            ans *= 2;
            h = h / 2;
        }
		cout << ((n > ans) ? "NO" : "YES") << endl;
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
