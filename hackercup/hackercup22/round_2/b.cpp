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


struct node{
	vector<int> alpha;
	int size;
	bool ans;
	node(){
		alpha.assign(26, 0);
		ans = true;
		size = 0;
	}
};
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
 
	void build(string &arr){
        init(arr.size());
		build(arr, 0, 0, size);
	}
 
 	void build(string &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				node newNode = node();
				newNode.alpha[arr[lx]-'a']++;
				newNode.size = 1;
				newNode.ans = 1;
				tree[x] = newNode;
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		tree[x] = merge(tree[2*x+1], tree[2*x+2]);
	}
 
	node query(int l, int r){
		return query(l, r, 0, 0, size);
	}

 	node query(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return node();
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		node left = query(l, r, 2*x+1, lx, m);
		node right = query(l, r, 2*x+2, m, rx);
		return merge(left, right);
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

	node merge(node &left, node &right){
		node newNode = node();
		For(i, 26){
			newNode.alpha[i] += left.alpha[i];
			newNode.alpha[i] += right.alpha[i];
		}
		newNode.size = left.size + right.size;
		return newNode;
	}
};

bool check(node &left, node &right){
	bool used = false;
	For(i, 26){
		int diff = abs(left.alpha[i] - right.alpha[i]);
		if(diff > 1){
			return false;
		}
		if(!used && diff == 1){
			used = 1;
			continue;
		}
		if(used && diff > 0){
			return false;
		}
	}
	return true && used;
}

void solve(){
	int tt; cin >> tt;
	For(t, tt){
		int ans = 0;
		string s;
		cin >> s;
		segment_tree<char, node> st;
		st.build(s);
		int q; cin >> q;
		For(i, q){
			int l, r; cin >> l >> r;
			l--;
			int m = (l+r) / 2;
			node left1 = st.query(l, m);
			node right1 = st.query(m, r);

			bool x = check(left1, right1);
			if(!x && (r-l) & 1){
				m++;
				node left2 = st.query(l, m);
				node right2 = st.query(m, r);
				x |= check(left2, right2);
			}
			ans += x;
		}
		cout << "Case #" << (t+1) << ": " << ans << endl;
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
