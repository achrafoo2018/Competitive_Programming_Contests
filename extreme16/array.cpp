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
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

int n, m, p;
template <class Array_Type, class Tree_Type>
class segment_tree{
public:
	int size;
	vector<Tree_Type> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(size * 2, 0);
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
		return tree[x] + query(l, r, 2*x+1, lx, m) + query(l, r, 2*x+2, m, rx);
	}

	void update(int l, int r, Array_Type v){
		update(l, r, v, 0, 0, size);
	}
 
	void update(int l, int r, Array_Type v, int x, int lx, int rx){
		if(rx <= l || lx >= r)	return;
		if(rx <= r && lx >= l){
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		update(l, r, v, 2*x+1, lx, m);
		update(l, r, v, 2*x+2, m, rx);
	}

	Tree_Type merge(int x){
		Tree_Type left = tree[2*x+1];
		Tree_Type right = tree[2*x+2];
		return left + right;
	}
};


void solve(){
	cin >> n >> m >> p;
	segment_tree<int, int> st;
	st.init(n);
	vector<int> ans(n, 0);
	vector<vi> querys;
	For(i, m){
		int l, r, k; cin >> l >> r >> k;
		l--;
		querys.push_back({l, r, k});
	}
	For(i, m){
		int l, r, k;
		l = querys[i][0];
		r = querys[i][1];
		k = querys[i][2];
		int pp = st.query(l, r);
		if(pp == 0){
			st.update(l, r, k);
			ans[r-1] = k;
		}else{
			For(j, m){
				int l2, r2, k2;
				l2 = querys[j][0];
				r2 = querys[j][1];
				k2 = querys[j][2];
				if(l2 )
			}
		}
	}
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
