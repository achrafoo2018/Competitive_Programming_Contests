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



void solve(){
	int n; cin >> n;
	vector<pll> arr(n);
	For(i, n){
		cin >> arr[i].second;
	}
	For(i, n){
		cin >> arr[i].first;
	}
	sort(all(arr));
	For(i, n-1){
		if(arr[i].second > arr[n-1].second){
			arr[i].second = max(arr[n-1].second, arr[i].second-arr[n-1].first+arr[i].first);
		}else if(arr[i].second < arr[n-1].second){
			arr[i].second = min(arr[n-1].second, arr[i].second+arr[n-1].first-arr[i].first);
		}
	}	
	long double ans = 0;
	For(i, n){
		swap(arr[i].second, arr[i].first);
	}
	sort(all(arr));
	cout << arr[0].first + (arr[n-1].first-arr[0].first)/2.0 << endl;
}

int main(){
	fastio;
	cout << setprecision(6);
	cout << fixed;
	// freopen("input.in", r", stdin);
	int t = 1;
	// freopen("output.(n)out", "w", stdout);
	cin >> t;
	while(t--)
		solve();
	return 0;
}
