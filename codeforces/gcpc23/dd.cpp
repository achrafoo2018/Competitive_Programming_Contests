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
ll n,q;
const ll prime=1e9+7;
const ll prime2=998244353;
const ll prime3=7901;

const ll MOD = 998244353;
ll INF=2e18;
int a,b,c,d;
vector<ld> types;
ld dp[60][600];

ld work(int index,int sum){
	if(index==-1 && sum!=0) return 0.0;
	if(index==-1 && sum==0) return 1.0;
	if(sum<=0) return 0.0;
	if(dp[index][sum]!=-1.0) return dp[index][sum];
	int getyp=types[index];

	ld proba=0.0;
	for(int i=1;i<=getyp;i++){
		proba += ((1.0/(ld)getyp)) * work(index-1,sum-i);
	}
	return dp[index][sum]=proba;
}
void solve(){
	int f;
	cin >> a >> b >> c >> d >> f;

	for(int i=0;i<60;i++){
		for(int j=0;j<600;j++){
			dp[i][j]=-1.0;
		}
	}


	for(int i=0;i<a;i++){
		types.push_back(4);
	}

	for(int i=0;i<b;i++){
		types.push_back(6);
	}

		for(int i=0;i<c;i++){
		types.push_back(8);
	}

		for(int i=0;i<d;i++){
		types.push_back(12);
	}

	for(int i=0;i<f;i++){
		types.push_back(20);
	}

	for(int i=0;i<=500;i++){
		work(a+b+c+d+f-1,i);
	} 

	ld zero=0.0;

	vector<int> arr;
	for(int i=1;i<=500;i++){
		if(dp[a+b+c+d+f-1][i]>zero){
			arr.push_back(i);
		}
	}
	int l = 0, r = arr.size()-1;
	vector<int> ans;
	while(l <= r){
		ans.push_back(arr[l++]);
		ans.push_back(arr[r--]);
		l++, r--;
	}
	dd(ans);
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
