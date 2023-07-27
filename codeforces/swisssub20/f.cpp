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

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
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


struct Point{
	ll x, y;
	void read(){
		cin >> x >> y;
	}
	Point operator -(const Point& b) const{
		return Point{x- b.x, y-b.y};
	}
	void operator -= (const Point& b){
		x -= b.x;
		y -= b.y;
	}
	ll operator *(const Point& b) const{
		return x * b.y - y *b.x;
	}
};


void solve(){
	Point bl1, tr1;
	bl1.read(); tr1.read();
	Point bl2, tr2;
	bl2.read(); tr2.read();
	Point a = tr1 - bl1;
	Point b = tr2 - bl2;
	ll ans = max(a.x * a.y, b.x * b.y);
	if(tr1.y < bl2.y || tr2.y < bl1.y || tr1.x < bl2.x || tr2.x < bl1.x){
		cout << ans << endl;
		return;
	}
	Point p1, p2;
	
	a.x = max(bl1.x, bl2.x);
	a.y = min(bl1.y, bl2.y);
	b.x = min(tr1.x, tr2.x);
	b.y = max(tr1.y, tr2.y);
	p1 = b - a;

	a.x = min(bl1.x, bl2.x);
	a.y = max(bl1.y, bl2.y);
	b.x = max(tr1.x, tr2.x);
	b.y = min(tr1.y, tr2.y);
	p2 = b - a;

	if(p1.x >= 0 && p2.y >= 0){
		ans = max(ans, p1.x * p1.y);
		ans = max(ans, p2.x * p2.y);
	}
	
	cout << ans << endl;
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
