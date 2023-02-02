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
const int N = 1e5 + 5;

typedef long long ll;

struct node{
    ll sum;
    int mx;
    node(){
        sum=mx=0;
    }
    node(ll s, int m){
        sum=s;
        mx=m;
    }
};

node tree[4*N];
int n;
int a[N];

node mrg(node& a, node& b){
    return {a.sum+b.sum, max(a.mx, b.mx)};
}

void build(int id=0, int ns=0, int ne=n-1){
    if(ns==ne){
        tree[id]={a[ns], a[ns]};
        return ;
    }
    int l=2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id]=mrg(tree[l],tree[r]);
}


void updrng(int qs, int qe, int x, int id=0, int ns=0, int ne=n-1){
    if(ns>qe || ne<qs)
        return ;
    if(tree[id].mx<x)
        return ;
    if(ns==ne){
        int v = tree[id].sum;
        tree[id]= {v%x, v%x};
        return;
    }
    int l=2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    updrng(qs, qe,x,l, ns, md);
    updrng(qs, qe,x,r, md+1, ne);
    tree[id]=mrg(tree[l],tree[r]);
}

void updpos(int qp, int x, int id=0,int ns=0, int ne=n-1){
    if(ns>qp || qp>ne)
        return ;
    if(ns==ne){
        tree[id]={x,x};
        return ;
    }
    int l=2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    updpos(qp, x, l, ns, md);
    updpos(qp, x, r, md+1, ne);
    tree[id]=mrg(tree[l],tree[r]);
}

ll get(int qs, int qe,  int id=0, int ns=0, int ne=n-1){
    if(ns>qe ||ne<qs)
        return 0;
    if(qs<=ns && qe>=ne){
        return tree[id].sum;
    }
    int l=2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    return get(qs, qe, l, ns, md)+get(qs, qe, r, md+1, ne);

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
		For(i, n+1){
			arr[i] = 1;
		}
		build();
		
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
