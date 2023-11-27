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
vector<ll> poww={1};
vector<ll> p_hash;
const ll M = (1LL << 61) - 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
	__int128 mul(ll a, ll b) { return (__int128)a * b; }
	ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
void init(){
  
   while (poww.size() < 1005) {
			poww.push_back(mod_mul(poww.back(), B));
		}
}

class HashedString {

	// p_hash[i] is the hash of the first i characters of the given string
	vector<ll> p_hash;


  
  public:
  
	void init(const string &s){
    p_hash.resize(s.size()+1);
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	ll getHash(int start, int end) {
		ll raw_val =
			p_hash[end + 1] - mod_mul(p_hash[start], poww[end - start + 1]);
		return (raw_val + M) % M;
	}
};
void solve(){
  ll m;
  cin >>n >>m;
  vector<ll> lengths(n);
  vector<HashedString> vec;
  vector<string> strings;
  for(int i=0;i<n;i++){
    string s;
    cin >>s;
    HashedString hs;
    hs.init(s);
    vec.push_back(hs);
    lengths[i]=(int)s.length();
    strings.push_back(s);
  }

  for(int i=0;i<m;i++){
    string s;
    cin >>s;
    HashedString hss;
    hss.init(s);
    vector<ll> pref((int)s.length());
    vector<ll> suff((int)s.length());
    for(int j=0;j<n;j++){
      ll szz=lengths[j];
      for(int h=szz-1;h>=0;h--){
        if(h<2) break;
        
        if(hss.getHash(0,h)==vec[j].getHash(0,h)){
          pref[h]++;
          break;
        }
      }
      for(int h=0;h<(int)szz-2;h++){
        ll howmuch=(int)szz-h;
        // debug me here! alech el ork wel spork mayetmatchiwech!
        // debug() << imie(h) imie(h) imie(szz-1) imie(s.length()-howmuch) imie(strings[j]) imie(j);
        // debug()<< imie(hss.getHash(s.length()-howmuch,s.length()-1)) imie(vec[j].getHash(h,szz-1)) imie(s.length()-1) imie(s);
        if(hss.getHash(s.length()-howmuch,s.length()-1)==vec[j].getHash(h,szz-1)){
          suff[s.length()-howmuch]++;
          break;
        }
      }
    }
    for(int j=1;j<(int)s.length();j++){
      suff[j]+=suff[j-1];
    }
    ll cntr=0;
    ll maxi=0;
    for(int j=0;j<min(50,(int)s.length());j++){
      ll v=suff[j]*pref[j];
      maxi=max(maxi,v);
    }
    debug() << imie(suff) imie(pref);
    if(maxi>1){
      cout << "ambiguous"<<"\n";
    }else if(maxi==1){
      cout <<"YES"<<'\n';
    }else{
      cout <<"none"<<'\n';
    }
    
  }
}
	
	

 
int main() {
	fastInp;
	//init();
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


