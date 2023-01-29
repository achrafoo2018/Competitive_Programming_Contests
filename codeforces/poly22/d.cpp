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
	int n, m; cin >> n >> m;
	vector<pair<int, vi>> arr;
	int nbo = 0;
	For(i, n){
		vi res;
		int o = 0;
		For(j, m){
			int x; cin >> x;
			res.PB(x);
			o += (x == 1);
		}
		res.PB(i+1);
		arr.PB({o, res});
		nbo += o;
	}
	if(nbo % n != 0){
		cout << -1 << endl; return;
	}
	sort(all(arr));
	vector<tuple<int, int, int>> ans;
	int l = 0, r = n-1;
	while(l < r){
		auto &x = arr[r];
		auto &y = arr[l];
		For(j, m){
			if(y.first == nbo/n || x.first == nbo/n)
				break;
			if(x.second[j] == 1 && y.second[j] == 0){
				ans.PB({y.second.back(), x.second.back(), j+1});
				x.second[j] = 0;
				x.first--;
				y.second[j] = 1;
				y.first++;
			}
		}
		if(x.first == nbo/n)
			r--;
		if(y.first == nbo/n)
			l++;
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
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
