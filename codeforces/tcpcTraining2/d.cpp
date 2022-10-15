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
	ofstream myfile;
	myfile.open("dwarf.out");
	int n, m;
	cin >> n >> m;
	vector<pair<ll, int>> costs;
	vll main_costs;
	For(i, n){
		ll x;
		cin >> x;
		costs.push_back(make_pair(x, i+1));
		main_costs.push_back(x);
	}
	sort(all(costs));
	vll dp(n);
	map<int, vector<pii>> crafts; 
	For(i, m){
		int a, x, y;
		cin >> a >> x >> y;
		crafts[a].push_back(make_pair(x, y));
	}
	if(n < 3){
		myfile << main_costs[0] << endl;
		return;
	}

	debug() << imie(costs);

	map<int, ll> prev;
	prev[costs[0].second] = costs[0].first;
	prev[costs[1].second] = costs[1].first;

	for(int i=2; i < n; i++){
		ll ans = costs[i].first;
		int item = costs[i].second;
		for(auto craft : crafts[item]){
			if(prev.find(craft.first) != prev.end() && prev.find(craft.second) != prev.end()){
				ans = min(ans, prev[craft.first] + prev[craft.second]);
			}
		}
		prev[item] = ans;
	}
	while(1){
		bool changed = false;
		for(int i=0; i < n; i++){
			ll ans = costs[i].first;
			int item = costs[i].second;
			for(auto craft : crafts[item]){
				if(prev.find(craft.first) != prev.end() && prev.find(craft.second) != prev.end()){
					ans = min(ans, prev[craft.first] + prev[craft.second]);
				}
			}
			if(prev[item] != ans)
				changed = true;
			prev[item] = ans;
		}
		if(!changed)
			break;
	}
	debug() << imie(prev);
	myfile << prev[1] << endl;

}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	freopen("dwarf.in", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
