#include "bits/stdc++.h"
using namespace std;
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3","unroll-loops")
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

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
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)

const int N = 2e6+5;
vector<int> sieve(N);
void init(){
	for(ll i=2;i<N;i++){
		if(sieve[i]==0){
			for(ll j=i;j<N;j+=i){
				 sieve[j]=i;
			}
		}
	}
}


int lookup[N][22];
int bin_log[N];

void buildSparseTable(int n){
	for(int k = 1; k < 22; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			lookup[i][k] = max(lookup[i][k-1], lookup[i+(1<<(k-1))][k-1]);
		}
	}
}
 
int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return max(lookup[L][k], lookup[R-(1<<k)+1][k]);
}

vi ans;
priority_queue<pii> pq;
void solve(){
	int n, q; cin >> n >> q;
	bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	For(i, n){
		int x; cin >> x;
		pq.push({x, -i});
	}
	ans.resize(n);
	int op = 0;
	while(!pq.empty()){
		pii x = pq.top();
		pq.pop();
		if(x.first == 1) continue;
		ans[-x.second] = ++op;
		lookup[-x.second][0]= op;
		x.first /= sieve[x.first];
		if(x.first > 1) pq.push(x);
	}
	buildSparseTable(n);
	while(q--){
		int l, r; cin >> l >> r;
		cout << query(--l, --r) << "\n";
	}
}

int main(){
	init();
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
