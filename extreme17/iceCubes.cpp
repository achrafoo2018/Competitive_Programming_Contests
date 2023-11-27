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
typedef vector<pll> vpll;

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

int n, m, k, b;
const int N=1001;
ll dp[N][N][21];
int grid[N][N];

ll work(int i, int j, int curr){
	if(curr >= k) return LONG_LONG_MIN;
	if(i == n-1 && j == m-1){
		if((grid[i][j] < b) && curr == k-1){
			return LONG_LONG_MIN;
		}
		return grid[i][j];
	}
	if(i >= n || j >= m) return LONG_LONG_MIN;
	ll &ans = dp[i][j][curr];
	if(ans != -1) return ans;
	if(grid[i][j] >= b){
		return ans = grid[i][j] + max(work(i+1, j, 0), work(i, j+1, 0));
	}
	return ans = grid[i][j] + max(work(i+1, j, curr+1), work(i, j+1, curr+1));
}
void solve(){
	cin >> n >> m >> k >> b;
	For(i, n){
		For(j, m){
			cin >> grid[i][j];
			For(p, 21){
				dp[i][j][p] = -1;
			}
		}
	}
	debug() << imie(grid);
	ll ans = work(0, 0, 0);
	if(ans < 0){
		cout << "IMPOSSIBLE" << endl; return;
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
	int i = 1;
	while(t--){
		cout << "Case " <<  i++ << ": ";
		solve();
	}
	return 0;
}
