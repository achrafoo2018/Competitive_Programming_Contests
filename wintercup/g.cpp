#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
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

const int maxN = 10e6+7;


vi sieve(int n){
	bool arr[n];
	vi primes;
	arr[0] = arr[1] = true;
	for(int i=2; i*i < n; i++){
		if(!arr[i]){
			for(int j=i*i; j < n; j += i)
				arr[j] = true;
		}
	}
	For(i, n){
		if(!arr[i])
			primes.push_back(i);
	}
	return primes;
}


void solve(){
	ll n, l;
	cin >> n >> l;
	vi primes = sieve(l+1);
	vi a(n), b(n);
	For(i, n)
		cin >> a[i];
	For(i, n)
		cin >> b[i];
	map<int, int> mp1;
	map<int, int> mp2;
	for(int i : primes){
		mp1[i] = 0;
		mp2[i] = 0;
		for(int j : a){
			if(j % i == 0){
				if((int)(log(j)/log(i)) == (log(j)/log(i))){
					mp1[i] += (log(j)/log(i));
				}else{
					int x = j;
					while(x % i == 0){
						mp1[i]++;
						x /= i;
					}
				}
			}
		}
		for(int j : b){
			if(j % i == 0){
				if((int)(log(j)/log(i)) == (log(j)/log(i))){
					mp2[i] += (log(j)/log(i));
				}else{
					int x = j;
					while(x % i == 0){
						mp2[i]++;
						x /= i;
					}
				}
			}
		}
	}
	int mn1 = INT_MAX;
	int mn2 = INT_MAX;
	for(auto i : mp1){
		mn1 = min(mn1, i.second);
	}
	for(auto i : mp2){
		mn2 = min(mn2, i.second);
	}
	if(mn1 >= mn2){
		cout << "Rami" << endl;
	}else{
		cout << "Yessine" << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
