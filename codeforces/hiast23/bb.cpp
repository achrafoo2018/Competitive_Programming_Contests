// WE ARE NOT HERE TO TAKE PART , WE ARE HERE TO TAKE OVER
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3","unroll-loops")

using namespace std;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
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
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define yes(check) cout << (check ? "YES" : "NO") << endl
typedef long long ll;
typedef long double ld;
ll n,q,d;
const ll prime=1e9+7;
const ll prime2=998244353;
const ll prime3=7901;

const ll MOD = 998244353;
ll INF=2e18;
const int NAX=2e6+5;
vector<int> sieve(NAX);
void init(){
	for(ll i=2;i<NAX;i++){
		if(sieve[i]==0){
			for(ll j=i;j<NAX;j+=i){
				 sieve[j]=i;
			}
		}
	}
}
const int MAX_N = 2e6+5;
const int LOG = 21;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];
int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return max(m[L][k], m[R-(1<<k)+1][k]);
}

void solve(){

	cin >> n >> q;
	priority_queue<pair<int,int>> pq;
	bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}

	for(int i=0;i<n;i++){
		int va;
		cin >> va;
		pq.push({va,-i});
	}
	
	int curr=0;

	
	while(!pq.empty()){
		pair<int,int> p=pq.top();
		pq.pop();
		
		int v=p.first;
		if(v==1){
			continue;
		}
		v=v/sieve[v];
		curr++;
		
		m[abs(p.second)][0]=curr;
		if(v==1){

		}else{
			pq.push({v,p.second});
		}
		//debug() << imie(p) imie(curr) imie(sieve[p.first]) imie(indexes);
	}

for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = max(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}
	for(int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;
		l--;r--;
		cout << query(l,r)<<"\n";

	}






	
}
	
	

 
int main() {
	fastInp;
	init();
	//debug() << imie(s);
	//freopen("grids.in","r",stdin);
	//freopen("res.out","w",stdout);
	// __gcd <long long> (x, y);
	int tc=1;
	//debug() << imie(sieve);
	//cin >> tc;
	//cout << setprecision(10)<<fixed;

	while(tc--){
		//i++;
		//cout <<"Test " << i << ":" << "\n";
		
		solve();
		
	}

	return 0;
}

/*
   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
 
 
 */
