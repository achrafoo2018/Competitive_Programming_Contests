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

#define yes cout << "YES\n";
#define no  cout << "NO\n";
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
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;


void solve(){
	string n; cin >> n;
	int k; cin >> k;
	set<char> st;
	if(k == 1){
		int i = 0;
		while(i < n.size() && n[i] == n[0]) i++;
		if(i == n.size() || (n[i]-'0') < (n[0]-'0')){
			For(i, n.size()) cout << n[0];			
		}else{
			For(i, n.size()) cout << (n[0]-'0') + 1;
		}
		cout << endl;
		return;
	}else{
		for(char i : n) st.insert(i);
		if(st.size() <= 2){
			cout << n << endl;
			return;
		}
		int idx = -1;
		Forr(i, n.size(), 1){
			if(n[i] != n[0]){
				idx = i; break;
			}
		}
		if(idx == -1){
			cout << n << endl; return;
		}
		bool ok1 = true, ok2 = true;
		Forr(i, n.size(), idx+1){
			if((n[i]-'0') > (n[0]-'0') && n[i] != n[idx]){
				ok1 = false;
			}
			if((n[i]-'0') > (n[idx]-'0') && n[i] != n[0]){
				ok2 = false;
			}
		}
		For(i, idx) cout << n[i];
		if(ok1 && ok2){
			cout << n[idx];
			Forr(i, n.size(), idx+1) cout << min((n[0]-'0') , (n[idx]-'0'));
		}else if(ok2){
			int i = idx;
			while(n[i] == n[idx] || n[i] == n[0]) cout << n[i++];
			cout << n[idx];
			while(++i < n.size()) cout << n[0];

		}else if(ok1){
			int i = idx;
			while(n[i] == n[idx] || n[i] == n[0]) cout << n[i++];
			cout << n[0];
			while(++i < n.size()) cout << n[idx];
		}else{
			cout << (n[idx]-'0')+1;
			int p = (((n[idx]-'0')+1) == (n[0]-'0') ? 0 : min((n[0]-'0') , (n[idx]-'0')+1));
			Forr(i, n.size(), idx+1) cout << p;
		}
		cout << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
