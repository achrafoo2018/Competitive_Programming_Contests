// THEY DON'T KNOW ME SON
#include <bits/stdc++.h>
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
#define For(i, n) for(int i=0; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;
typedef long long ll;
typedef long double ld;
ll n,q,d;
const ll prime=1e9+7;
const ll prime2=998244353;
const ll prime3=7901;

const ll MOD = 998244353;
ll INF=2e18;

void solve(){
	cin >> n;
	cin >> q;
	vector<ll> vec(n);
	ll maxi=0;
	for(int i=0;i<n;i++){
		cin >> vec[i];
		maxi=max(maxi,vec[i]);
	}
	ll biggest=-1;
	map<ll,int> mpfirstInd;
	set<ll> s;

	for(int i=0;i<n;i++){
		if(vec[i] > biggest){
			mpfirstInd[vec[i]]=i;
			biggest=vec[i];
			s.insert(vec[i]);
		}
	}
	vector<ll> prefMin(n);
	prefMin[n-1]=vec[n-1];
	for(int i=n-2;i>=0;i--){
		prefMin[i]=min(prefMin[i+1],vec[i]);
	}
    debug() << imie(prefMin);
	prefMin[0]=0;
	
	debug() << imie(s);

	while(q--){
		int u,v;
		cin >> u >> v;
        if(u > maxi || v > maxi){
            cout << "No"<<"\n";
            continue;
        }
		if(u <= v){
            cout <<"Yes"<<"\n";
		}else{
			// u>v 
			auto it = s.lower_bound(u);

            int index = mpfirstInd[*it];
            debug() << imie(index);

            int mini = prefMin[index];
            debug() << imie(mini);
            debug() << imie(prefMin);
            if(mini <= v){
                cout << "Yes" <<"\n";
            }else{
                cout << "No" <<"\n";
            }
			
		}
	}
}
	
	

 
int main() {
	fastInp;
	//init();
	//debug() << imie(s);
	// freopen("milk.in","r",stdin);
	//freopen("res.out","w",stdout);
	// __gcd <long long> (x, y);
	int tc=1;
	//debug() << imie(sieve);
	cin >> tc;
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
