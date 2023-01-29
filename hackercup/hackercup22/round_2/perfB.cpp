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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
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



bool check(vi &left, vi &right){
	bool used = false;
	For(i, 26){
		int diff = abs(left[i] - right[i]);
		if(diff > 1){
			return false;
		}
		if(!used && diff == 1){
			used = 1;
			continue;
		}
		if(used && diff > 0){
			return false;
		}
	}
	return true && used;
}

vi merge(int left[26], int right[26]){
	vi ans(26, 0);
	For(i, 26)
		ans[i] = right[i] - left[i];
	return ans;
}

const int N = 1e6+7;
int pref[N][26];

void solve(){
	int tt; cin >> tt;
	For(t, tt){
		int ans = 0;
		string s;
		cin >> s;
		int q; cin >> q;
		int n = s.size();
		For(i, n){
			For(j, 26)
				pref[i][j] = 0;
		}
		for(int i=1; i <= n; i++){
            For(j, 26){
                pref[i][j] = pref[i-1][j];
            }
			int c = (s[i-1] - 'a');
			pref[i][c]++;
		}
		For(i, q){
			int l, r; cin >> l >> r;
			l--;
			int m = (l+r) / 2; 
			vi left1 = merge(pref[l], pref[m]);
			vi right1 = merge(pref[m], pref[r]);
			m++;
			vi left2 = merge(pref[l], pref[m]);
			vi right2 = merge(pref[m], pref[r]);
			ans += (check(left1, right1) || check(left2, right2));
		}
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
