#include "bits/stdc++.h"
/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠏⢀⣀⣤⣤⣤⣤⣤⣤⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣿⣿⣿⡿⣿⣴⢶⣶⣿⣟⣶⣿⣭⠿⠦⠤⠽⣷⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣿⡿⢫⣿⢋⣠⣿⣿⡶⢻⡏⠄⠄⠄⠄⠄⠄⠄⠉⠙⢦⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⡿⠋⠈⣸⣿⣿⣿⡿⠿⠄⠈⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⢯⠋⠈⠄⣴⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠸⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠒⠄⠄⢰⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢷⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢼⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⢀⡀⠤⠤⠤⣀⠄⢀⡀⠤⠤⠤⣀⣱⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢸⣿⣿⣿⣿⣿⠄⠄⠄⢀⡖⠁⠄⠄⠄⠄⠄⠱⡏⠄⠄⠄⠄⠈⠱⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠄⠄⠄⠄
⠄⠄⠄⠈⣿⣿⣿⣿⣿⡆⠄⠄⢸⠄⠄⠴⠆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠶⠄⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⢀⡴⠋⠉⢹⡶⠶⢤
⠄⠄⠄⠄⢸⣿⣿⣿⣿⣿⣸⢻⡜⡄⠄⠄⠄⠄⠄⠄⢀⠶⠒⠒⠄⠐⣄⡼⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣾⣿⣿⠟⠛⠓⠶⣏⠄⠄⣀
⠄⠄⠄⢸⢧⣿⣿⣿⣿⣿⡿⠄⠷⠙⠲⠄⠄⡀⠠⠔⠁⠄⠄⠄⢀⣠⡇⡧⠄⠄⠄⠄⠄⠄⠄⠄⠄⣴⣿⣿⣿⡇⠄⡀⠄⠄⠈⢦⠞⠁
⠄⠄⠄⢸⡈⢻⣿⣿⣿⡿⠧⣄⠄⠄⠄⢀⡴⠖⠒⠚⠛⠛⠛⠛⠉⠄⠈⠙⠦⣀⣠⣀⠄⠄⠄⠄⢰⣿⣿⣿⣿⠄⠄⠈⢢⡀⠠⢾⠄⠄
⠄⠄⠄⠄⣴⣾⣿⣿⣿⢲⡶⡄⠄⢀⡶⠋⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢁⠄⢸⠄⠄⠄⠄⣸⣿⣿⠟⠋⠄⠄⠄⡎⠄⠄⠈⠉⠄
⡀⠄⠄⠘⣿⣿⣿⣿⣿⣦⣤⡴⠄⣾⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢰⡷⢰⠃⠄⠄⣠⣾⣿⠟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠
⠙⢦⡀⠄⠈⠛⢻⣿⣿⣿⣿⡇⠄⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢦⣀⣠⠎⢀⣤⣾⡿⠋⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠞⠄
⠄⠄⠈⠳⢄⠄⢸⣿⣿⣿⣿⡇⠄⠙⣆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡴⠃⠄⣠⣴⣿⠟⠋⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡰⠁⠄⠄
⠄⠄⠄⠄⠈⠙⢾⣿⣿⣿⣿⡇⠄⠄⠈⠳⠤⣀⡀⠄⠄⢀⣀⠤⡖⠋⢀⡤⠾⠿⣏⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⠎⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢨⠇⠙⢿⠷⠖⠒⠛⠓⠒⠚⠛⠯⡉⠉⠄⠄⡷⠶⠯⡁⠄⠄⠄⠙⠢⡀⠄⠄⠄⠄⠄⠄⠄⠄⢀⠜⠁⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⢀⡌⠄⠄⠄⠳⡀⠄⠄⠄⠄⠄⡌⠄⠙⢆⠄⠄⡧⠂⠄⢡⠄⠄⠄⠄⠄⠈⠢⡀⠄⠄⠄⠄⢀⡔⠁⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⢀⠌⠄⠄⠄⠄⠄⠰⡀⠄⠄⠄⢰⠃⠄⠄⠈⠣⡴⠉⠡⡀⠈⡆⠄⠄⠄⠄⠄⠄⠘⠄⠄⢀⡴⠊⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⡠⠊⠄⠄⠄⠄⠄⠄⠄⢩⠉⠉⠉⠉⠄⠄⠄⠄⠄⠄⠄⠄⠱⡀⠁⠄⠄⠄⠄⠄⠄⠄⠈⣶⠊⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣷⣄⣠⠞⠁⠄⠄⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢡⠄⠄⠄⠄⠄⠄⠄⠄⢠⠎⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣎⡁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡆⠄⠄⠄⠄⢀⡠⠞⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣶⣤⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⢤⡤⠴⠒⠊⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠻⠿⢿⣿⣿⣿⣿⠏⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠢⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
*/
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

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
	ll k;
	cin >> n >> k;
	vll arr(n);
	For(i, n)
		cin >> arr[i];
	ll ans = 0;
	int j = 0;
	int mn = 0, mx = 0;
	For(i, n){
		if(arr[i] <= arr[mn])
			mn = i;
		if(arr[i] >= arr[mx])
			mx = i;
		while((arr[mx]-arr[mn]) > k && j <= i){
			if(arr[i] == arr[mx]){
				j = ++mn;
				for(int m = j; m <= i; m++){
					if(arr[m] <= arr[mn])
						mn = m;
				}
			}
			else if(arr[i] == arr[mn]){
				j = ++mx;
				for(int m = j; m <= i; m++){
					if(arr[m] >= arr[mx])
						mx = m;
				}
			}
		}
		ans += i - j + 1;
	}
	cout << ans << endl;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
