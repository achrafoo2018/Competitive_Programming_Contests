#include <bits/stdc++.h>
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

#define re1(x) scanf("%lld",&x)
#define re2(x,y) scanf("%lld%lld",&x,&y)
#define re3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;
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



ll n,q;
const int N = 2e5+7;
ll arr[N];
struct node{
	ll t;
	ll lazy;
};
node st[4*N];
void propogate(ll ss,ll se,ll si){
	if(st[si].lazy!=0){
		st[si].t=(st[si].lazy*(se-ss+1));
		if(ss!=se){
			st[2*si+1].lazy=(st[si].lazy);
			st[2*si+2].lazy=(st[si].lazy);
		}
		st[si].lazy=0;
	}
	if(ss>se){
		return;
	}
	return;
}
void update(ll ss,ll se,ll qs,ll qe,ll si,ll val){
		propogate(ss,se,si);
		if(ss>se||ss>qe||se<qs){
			return;
		}
		if(ss>=qs && se<=qe){
			st[si].lazy=val;
			propogate(ss,se,si);
			return;
		}
		ll mid=(ss+se)/2;
		update(ss,mid,qs,qe,2*si+1,val);
		update(mid+1,se,qs,qe,2*si+2,val);
		st[si].t=(st[2*si+1].t)+(st[2*si+2].t);
		return;
}
ll query(ll ss,ll se,ll qs,ll qe,ll si){
	propogate(ss,se,si);
	if(ss>se||ss>qe||se<qs){
		return 0;
	}
	if(ss>=qs && qe>=se){
		return st[si].t;
	}
	ll mid=(ss+se)/2;
	ll p1=query(ss,mid,qs,qe,2*si+1);
	ll p2=query(mid+1,se,qs,qe,2*si+2);
	return p1+p2;
}
void build(ll ss,ll se,ll si){
	if(ss>se){
		return;
	}
	if(ss==se){
		st[si].t=arr[ss];
		st[si].lazy=0;
		return;
	}
	ll mid=(ss+se)/2;
	build(ss,mid,2*si+1);
	build(mid+1,se,2*si+2);
	st[si].t=st[2*si+1].t+st[2*si+2].t;
}

int main(){
	ll t;
	re1(t);
	while(t--){
		int n, q; cin >> n >> q;
		vector<pair<int, pii>> lines(q);
		For(i, q)
			cin >> lines[i].second.first >> lines[i].second.second >> lines[i].first;
		sort(all(lines));
		for(ll i=0;i<=4*n;i++){
			st[i].t=0;
			st[i].lazy=0;
		}
		For(i, n+1){
			arr[i] = 1;
		}
		build(0,n-1,0);
		For(i, q){
			int l = lines[i].second.first, r = lines[i].second.second;
			l--; r--;
			int x = query(0,n-1,l,r,0);
			debug() << imie(x);
			if(x){
				update(0,n-1,l,r,0,0);
				update(0,n-1,l,l,0,1);
				update(0,n-1,l,r,0,1);
			}
		}
		cout << query(0,n-1,0,n-1,0) << endl;
	}
	return 0;
}
