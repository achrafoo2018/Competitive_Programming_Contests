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

template <class Array_Type, class Tree_Type>
class segment_tree{
public:
	int size;
	vector<Tree_Type> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.resize(size * 2);
	}
 
	void build(vector<Array_Type> &arr){
        init(arr.size());
		build(arr, 0, 0, size);
	}
 
 	void build(vector<Array_Type> &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				tree[x] = arr[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		tree[x] = merge(x);
	}
 
	Tree_Type query(int l, int r){
		return query(l, r, 0, 0, size);
	}

 	Tree_Type query(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		return query(l, r, 2*x+1, lx, m) + query(l, r, 2*x+2, m, rx);
	}

	void update(int i, Array_Type v){
		update(i, v, 0, 0, size);
	}
 
	void update(int i, Array_Type v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if(i < m){
			update(i, v, 2*x+1, lx, m);
		}else{
			update(i, v, 2*x+2, m, rx);
		}
		tree[x] = merge(x);
	}

	Tree_Type merge(int x){
		Tree_Type left = tree[2*x+1];
		Tree_Type right = tree[2*x+2];
		return left + right;
	}
};


const int N = 107;
map<int, int> dp[N][N];
int arr[N];
int n;
string s;

segment_tree<int, int> nbo, nbz;
ll work(int i, int prev, int diff){
	if(i == n){
		debug() << imie(diff);
		if(diff == 0) return 0;
		return INT_MAX;	
	}
	// if(diff == 0) return 0;
	if(dp[i][prev].find(diff) != dp[i][prev].end()){
		return dp[i][prev][diff];
	}
	ll ans = work(i+1, prev, diff);
	if(s[i] == '0'){
		return dp[i][prev][diff] = ans;
	}
	Forr(j, n, max(i+1, prev+1)){
		if(s[j] == '0'){
			int x = arr[j];
			int xx = nbz.query(j, n);
			int y = arr[i];
			int yy = nbo.query(i, n);
			int tmp = diff;
			tmp += (x -yy);
			tmp += (xx - y);
			ans = min(ans, 1 + work(i+1, j, tmp));
		}
	}	
	return dp[i][prev][diff] = ans;
}

void solve(){
	cin >> s;
	n = s.size();
	nbo.init(n);
	nbz.init(n);
	For(i, n){
		nbo.update(i, (s[i] == '1'));
		nbz.update(i, (s[i] == '0'));
	}
	int x = 0, y = 0;
	For(i, n){
		if(s[i] == '1'){
			int p = nbz.query(i, n);
			arr[i] = p;
			x += p;
		}else{
			int p = nbo.query(i, n);
			arr[i] = p;
			y += p;
		}
	}
	debug() << imie(x) imie(y);
	if(x == y){
		cout << 0 << endl; return;
	}
	cout << work(0, 0, (x- y)) << endl;
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
