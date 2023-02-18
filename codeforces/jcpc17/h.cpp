#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define endl '\n';
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;


void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vi arr;
	For(i, n){
		if(s[i] == '+')
			arr.PB(i);
	}
	// debug() << imie(arr);
	auto check = [&](int mid){
		int idx = -1;
		For(i, arr.size()){
			int l, r;
			if(i == 0){
				l = 0;
			}else{
				l = arr[i-1]+mid;
			}
			if(i == arr.size()-1){
				r = n-1;
			}else{
				r = arr[i+1]-mid;
			}
			if(l >= r){
				idx = arr[i]; break;
			}
		}
		vi distances;
		debug() << imie(mid) imie(idx);
		if(idx != -1){
			int dist = 0;
			bool used = false;
			bool cond = true;
			For(i, n){
				dist++;
				if(i != idx && s[i] == '+'){
					distances.PB(dist);
					dist = 0;
				}
			}
			distances.PB(dist);
			debug() << imie(distances);
			for(int d : distances){
				if(d > mid){
					if(d/2 > mid || used){
						cond = false; break;
					}
					used = true;
				}
			}
			debug() << imie(cond);
			if(cond) return true;
		}
		int dist = 0;
		bool used = false;
		bool cond = true;
		int prev = 0;
		For(i, n){
			dist++;
			if(s[i] == '+'){
				prev = mid-dist+1;
				dist = 0;
			}
			if(dist > mid){
				if(dist-prev > mid || used){
					cond = false;
					break;
				}
				dist -= prev;
				used = true;
			}	
		}
		if(cond) return true;
		dist = 0;
		used = false;
		cond = true;
		prev = 0;
		for(int i=n-1; i >= 0; i--){
			dist++;
			if(s[i] == '+'){
				prev = mid-dist+1;
				dist = 0;
			}
			if(dist > mid){
				if(dist-prev > mid || used){
					cond = false;
					break;
				}
				dist -= prev;
				used = true;
			}	
		}
		return cond;
	};
	int l = 0, r = 1e5+7;
	int ans = 0;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	cout << ans << endl;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("stations.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
