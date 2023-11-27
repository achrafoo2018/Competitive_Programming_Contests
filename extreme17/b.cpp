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
bool test=false;
map<ll,ll> seen;



void go(int v,map<ll,ll>& mp){
  //debug() << imie(v);
    if(v==1) return;
   // debug() << imie(v);
  if(mp[v]){
    for(auto el:mp){
      seen[el.first]=true;
    }
    return;
  }
  mp[v]=true;

  ll temp=v;
  ll other=0;
  while(temp>0){
    other+=(temp%10)*(temp%10);
    temp=temp/10;
  }
 // mp[other]=true;
 //debug() << imie(other);
  go(other,mp);
}
// problem Link : https://cses.fi/problemset/result/5774825/
ll dp[16][2][1300];
ll solverec(string& num,int digNum,bool tight,int sum){
  	if(sum<0) return 0;
	if(digNum==0 && sum==0){
		return 1;
	}else if(digNum==0) return 0;
	if(dp[digNum][tight][sum]!=-1) return dp[digNum][tight][sum];
	int upperBound=tight? num[(int)num.length()-digNum]-'0':9;
	ll answer=0;
	debug() << imie(num);
	for(int i=0;i<=upperBound;i++){
		//if( !leading) continue;
		

			answer+=solverec(num,digNum-1,tight&&(upperBound==i),sum-(i*i));
		
	}

	return dp[digNum][tight][sum]=answer;
}
void solve(){

 //memset(dp, -1, sizeof dp);
	map<ll,ll> mp;
  for(int i=1;i<=1300;i++){
	mp.clear();
   // mp[i]=true;
    go(i,mp);
  }
  ll l,r;
  cin >>l >>r;
  ll v=0;
  l--;
  
//   for(int i=l;i<=r;i++){
//     if(!seen[i]) v++;
//   }
  string s1=to_string(l);
string s2=to_string(r);
  ll nothappy=0;
  memset(dp,-1, sizeof dp);
  for(int i=1300;i>=1;i--){
    if(!seen[i]) continue;
    //Y=i;
    //memset(dp,-1, sizeof dp);
    nothappy+=solverec(s2,(int)s2.size(),1,i);
   // debug() << imie(
  }
  memset(dp,-1, sizeof dp);
  for(int i=1300;i>=1;i--){
    if(!seen[i]) continue;
    //Y=i;
    //memset(dp,-1, sizeof dp);
    nothappy-=solverec(s1,(int)s1.size(),1,i);
   // debug() << imie(
  }
  debug() << imie(nothappy);
  cout <<  r-(l)-nothappy<<'\n';
  //cout << v <<'\n';

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


