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

#define yes cout << "YES\n";
#define no  cout << "NO\n";
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
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
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;


void solve(){
	int n; cin >> n;
	string a, b; cin >> a >> b;
	int diff = 0;
	vpii ans;
	For(i, n){
		diff += (a[i] != b[i]);
		if(a[i] == '1'){
			ans.push_back({i+1, i+1});
		}
	}
	if(diff != 0 && diff != n){
		no;
		return;
	}
	yes;
	if(a == b && ans.size() == 0){
		cout << 0 << endl;
		return;
	}
	if(ans.size() == 0){
		ans.push_back({1, n});
		For(i, n){
			ans.push_back({i+1, i+1});
		}
	}
	int nbones = ans.size();
	if((diff == n && (nbones % 2 == 0)) || (diff == 0 && (nbones % 2 == 1))){
		pii tmp = ans.back();
		ans.pop_back();
		ans.push_back({1, n});
		if(tmp.first == n){
			ans.push_back({1, n-1});
		}else if(tmp.first == 1){
			ans.push_back({2, n});
		}else{
			ans.push_back({1, tmp.first-1});
			ans.push_back({1, n});
			ans.push_back({1, tmp.first});
		}
	}
	cout << ans.size() << endl;
	For(i, ans.size()){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
