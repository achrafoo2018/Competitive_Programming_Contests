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

int n, q;
vector<pair<pll, int>> arr;
const int N = 2e5+7;
ll a[N], b[N];
vvi graph;
vi visited;
vi ans;

ll dfs(int i, ll mx){
	visited[i] = 1;
	for(int e : graph[i]){
		if(!visited[e]){
			mx = max(mx, dfs(e, max(mx, b[e])));
		}
	}
	return ans[i] = mx;
}


template <class Array_Type, class Tree_Type>
class segment_tree{
public:
	int size;
	vector<Tree_Type> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(size * 2, INT_MIN);
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
		if(lx >= r || l >= rx) return INT_MIN;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		return max(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
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
		return max(left, right);
	}
};

void solve(){
	graph.clear();
	ans.clear();
	cin >> n;
	arr.resize(n);
	graph.resize(n);
	visited.assign(n, 0);
	ans.resize(n);
	For(i, n){
		cin >> arr[i].first.first >> arr[i].first.second >> a[i] >> b[i];
		arr[i].second = i;
	}
	sort(all(arr));
	For(i, n){
		int x = arr[i].second;
		if(i == n-1) break;
		int y = arr[i+1].second;
		if(b[x] >= arr[i+1].first.first){
			graph[x].PB(y);
			graph[y].PB(x);
		}
	}
	For(i, n){
		int x = arr[i].second;
		if(!visited[x]){
			dfs(x, b[x]);
		}
	}
	segment_tree<int, int> st;
	vi pp(n);
	For(i, n){
		pp[i] = ans[arr[i].second];
	}
	st.build(pp);
	cin >> q;
	debug() << imie(arr);
	while(q--){
		int x; cin >> x;
		int l = 0, r = n-1;
		int res = x;
		int ll = INT_MAX, rr = -1;
		while(l <= r){
			int mid = l + (r-l)/2;
			bool cond = arr[mid].first.first <= x && arr[mid].first.second >= x;
			if(cond)
				rr = max(rr, mid);
			if(x >= arr[mid].first.first){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		l = 0, r = n-1;
		while(l <= r){
			int mid = l + (r-l)/2;
			bool cond = arr[mid].first.first <= x && arr[mid].first.second >= x;
			if(cond) ll = min(ll, mid);
			if(x <= arr[mid].first.second){
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		debug() << imie(ll) imie(rr);
		if(rr != -1 && ll != INT_MIN) res = max(res, st.query(ll, rr+1));
		cout << res << " ";
	}
	cout << endl;
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
