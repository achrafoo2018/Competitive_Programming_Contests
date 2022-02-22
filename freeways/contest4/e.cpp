#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
int n;
bool check(vvll arr, ll mid){
	vector<bool> visited(n, false);
	while(1){
		ll tmp_mid = mid;
		For(i, n){
			if(visited[i])
				continue;
			ll k = arr[i].size();
			ll ss = 0;
			ll j = 0;
			while(j < k){
				if(arr[i][j] >= tmp_mid+ss)
					break;
				ss++;
				j++;
			}
			if(j == k){
				tmp_mid += k;
				visited[i] = true;
			}
		}
		if(tmp_mid == mid)
			break;
		mid = tmp_mid;
	}
	For(i, n){
		if(!visited[i])
			return false;
	}
	return true;
}
void solve(){
	cin >> n;
	vvll arr(n);
	For(i, n){
		int k;
		cin >> k;
		For(j, k){
			ll x;
			cin >> x;
			arr[i].push_back(x);
		}
	}
	ll l = 0, h = 1e9+7, ans = 1e9+10;
	while(l < h){
		ll mid = (l+h+1)/2;
		if(check(arr, mid)){
			h = mid-1;
			ans = min(ans, mid);
		}
		else
			l = mid;
	}
	cout << ans << endl;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
