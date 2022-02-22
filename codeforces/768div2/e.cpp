#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
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
	int n;
	cin >> n;
	vi arr(n);
	map<int, queue<int>> mp;
	For(i, n){
		cin >> arr[i];
		mp[arr[i]].push(i);
	}
	vpii ans;
	for(auto i : mp){
		int idx1 = i.second.front();
		i.second.pop();
		if(i.second.empty())
			continue;
		int idx2 = i.second.front();
		i.second.pop();
		ans.push_back({idx1, idx2});
	}
	sort(all(ans));
	for(int i=1; i < ans.size(); i++){
		if(ans[i].first <= ans[i-1].second && ans[i].second > ans[i-1].second){
			if(ans[i].second - ans[i].first - 1 >= ans[i-1].second - ans[i-1].first - 1){
				ans[i-1].first = 0;
				ans[i-1].second = 1;
			}else{
				ans[i].first = ans[i-1].first;
				ans[i].second = ans[i-1].second;
				ans[i-1].first = 0;
				ans[i-1].second = 1;
			}
		}
	}
	ll res = 0;
	for(auto i : ans){
		res += i.second - i.first - 1;
	}
	cout << res << endl;
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
