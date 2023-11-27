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


void solve(){
	int r, c; cin >> r >> c;
	vvchr grid(r, vchr(c));
	For(i, r){
		For(j, c) cin >> grid[i][j];
	}
	vvi visited(r, vi(c));
	vpii dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	auto check = [&](pii pos){
		return (pos.first >= 0 && pos.first < r) && (pos.second >= 0 && pos.second < c);
	};
	For(i, r){
		For(j, c){
			if(grid[i][j] != 'W' || visited[i][j]) continue;
			debug() << imie(i) imie(j);
			int cnt = 0;
			vvi counted(r, vi(c));
			queue<pii> q;
			q.push({i, j});
			while(!q.empty()){
				pii pos = q.front();
				q.pop();
				if(!check(pos)) continue;
				if(!counted[pos.first][pos.second] && grid[pos.first][pos.second] == '.'){
					cnt++;
					counted[pos.first][pos.second] = 1;
				}
				if(grid[pos.first][pos.second] != 'W') continue;
				visited[pos.first][pos.second] = 1;
				for(pii dir : dirs){
					pii y = {pos.first + dir.first, pos.second + dir.second};
					if(check(y) && !visited[y.first][y.second]){
						q.push(y);
					}
				}
			}
			if(cnt <= 1){
				yes;
				return;
			}
		}
	}
	no;
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
		cout << "Case #" << i++ << ": ";
		solve();
	}
	return 0;
}
