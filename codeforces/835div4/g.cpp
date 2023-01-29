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

set<int> weights;
vector<vpii> adj;
int n, a, b;
vector<bool> visited;
void dfs1(int node, int x){
	visited[node] = 1;
	for(auto edge : adj[node]){
		if(!visited[edge.first]){
			weights.insert(x ^ edge.second);
			dfs1(edge.first, x ^ edge.second);
		}
	}
}

bool dfs2(int node, int x){
	visited[node] = 1;
	if(node == b) return x == 0;
	if(weights.find(x) != weights.end()) return true;
	bool ans = false;
	for(auto edge : adj[node]){
		if(!visited[edge.first]){
			ans = ans || dfs2(edge.first, x ^ edge.second);
		}
	}
	return ans;
}


void solve(){
	cin >> n;
	cin >> a >> b;
	weights.clear();
	adj.clear();
	adj.resize(n+1);
	visited.assign(n+1, false);
	For(i, n-1){
		int u, v, w; cin >> u >> v >> w;
		adj[u].PB({v, w});
		adj[v].PB({u, w});
	}
	dfs1(b, 0);
	visited.assign(n+1, false);
	if(dfs2(a, 0)){
		yes;
	}else{
		no;
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
