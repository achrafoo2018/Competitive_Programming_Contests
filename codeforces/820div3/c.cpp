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

void solve(){
	string s; cin >> s;
	int n = s.size();
	map<char, vector<int>> mp;
	for(int i=1; i < n-1; i++){
		mp[s[i]].push_back(i+1);
	}
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	vector<int> ans;
	if(s[0]-'a' > s[n-1]-'a'){
		for(int i=s[0]-'a'; i >= s[n-1]-'a'; i--){
			if(mp.find(alpha[i]) != mp.end()){
				for(int j : mp[alpha[i]]){
					ans.push_back(j);
				}
			}
		}
	}else{
		for(int i=s[0]-'a'; i <= s[n-1]-'a'; i++){
			if(mp.find(alpha[i]) != mp.end()){
				for(int j : mp[alpha[i]]){
					ans.push_back(j);
				}
			}
		}
	}
	cout << abs(s[0]-s[n-1]) << " " << ans.size() + 2 << endl;
	cout << 1 << " ";
	for(int i : ans){
		cout << i << " ";
	}
	cout << n << endl;
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
