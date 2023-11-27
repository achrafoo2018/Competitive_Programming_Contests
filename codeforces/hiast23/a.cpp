// WE ARE NOT HERE TO TAKE PART , WE ARE HERE TO TAKE OVER
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
ll dp[105][3][3][3][3][3][3][3][3][3][3];


vector<ll> items;
ll work(int index,int zero,int one,int two,int three,int four,int five,int six,int seven,int eight,int nine ){
	if(index>=n) return 0;
	
	if(dp[index][zero][one][two][three][four][five][six][seven][eight][nine]!=-1){
		return dp[index][zero][one][two][three][four][five][six][seven][eight][nine];
	}
	debug() << imie(index) imie(zero);
	vector<int> vec={zero,one,two,three, four, five,six,seven,eight,nine};

	ll ekhedh=items[index];
	bool t=true;
	while(ekhedh>0){
		int v=ekhedh%10;
		vec[v]++;
		if(vec[v]>2) {
			t=false;
			break;
		}
		ekhedh=ekhedh/10;

	}
	ll value=work(index+1,zero,one,two,three,four,five,six,seven,eight,nine);
	if(t){
		value=max(items[index]+work(index+1,vec[0],vec[1],vec[2],vec[3],vec[4],vec[5],vec[6],vec[7],vec[8],vec[9]),value);
	}
	debug() << imie(value);
	return dp[index][zero][one][two][three][four][five][six][seven][eight][nine]=value;

}
void solve(){
	cin >> n;
	items.resize(n);
	
	for(int i=0;i<n;i++){
		cin >> items[i];
	}

	for(int i=0;i<n;i++){
		memset(dp[i],-1,sizeof dp[i]);
	}
	for(int i=0;i<n;i++){
		debug() << imie(dp[i][0][0][0][0][0][0][0][0][0][1]);
	}

	cout << work(0,0,0,0,0,0,0,0,0,0,0)<<"\n";


	
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
