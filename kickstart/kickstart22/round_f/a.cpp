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
	int tt; cin >> tt;
	For(t, tt){
		int ans = 0;
		int n; cin >> n;
		vector<vector<string>> arr1(n, vector<string>(3));
		vector<vector<string>> arr2(n, vector<string>(3));
		For(i, n){
			For(j, 3){
				cin >> arr1[i][j];
				arr2[i][j] = arr1[i][j];
			}
		}
		sort(all(arr1), [&](vector<string> s1, vector<string> s2){
			if(s1[0] < s2[0])
				return true;
			else if(s1[0] > s2[0])
				return false;
			else{
				return atoi(s1[2].c_str()) <= atoi(s2[2].c_str());
			}
		});
		sort(all(arr2), [&](vector<string> s1, vector<string> s2){
			if(atoi(s1[1].c_str()) < atoi(s2[1].c_str()))
				return true;
			else if(atoi(s1[1].c_str()) > atoi(s2[1].c_str()))
				return false;
			else{
				return atoi(s1[2].c_str()) <= atoi(s2[2].c_str());
			}
		});

		For(i, n){
			if(arr1[i][2] == arr2[i][2])
				ans++;
		}
		cout << "Case #" << (t+1) << ": " << ans << "\n";
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
