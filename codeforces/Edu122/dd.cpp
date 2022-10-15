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

ll work(vpii vp, int k, int ans, int idx){
	if(k == 0 || idx >= n)
		return ans;
	if(k - vp[idx].second < 0)
		return 0;
	return max(work(vp, k-vp[idx].second, ans+vp[idx].first, idx+1), work(vp, k, ans, idx+1));
}

void solve(){
	int k;
	cin >> n >> k;
	vi b(n), c(n);
	For(i, n)
		cin >> b[i];
	For(i, n)
		cin >> c[i];
	vi arr(n, 1);
	vi op(n, 0);
	For(i, n){
		int l2 = log2(b[i]);
		op[i] = l2;
		int r = b[i] - (1 << l2);
		int d = (1 << l2);
		while(r != 0){
			int x =  ceil(d / (double)r);
			d += floor(d/(double)x);
			r = b[i] - d;
			op[i]++;
		}
	}
	vpii vp(n);
	For(i, n){
		vp[i] = {c[i], op[i]};
	}
	sort(all(vp));
	cout << work(vp, k, 0, 0) << endl;
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