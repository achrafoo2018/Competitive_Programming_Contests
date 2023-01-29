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

int r, c;
bool cond;

vector<string> grid;
vector<string> ans;

void work(int i, int j, int ii, int jj){
	if(i > ii || (i >= ii && j > jj) || i < 0 || j < 0 || i > r || j > c){
		return;
	}
	if(ans[i][j] != '^'){
		return;
	}
	int friends = 0;
	friends += ((j+1) < c && ans[i][j+1] == '^');
	friends += ((i+1) < r && ans[i+1][j] == '^');
	friends += ((j-1) >= 0 && ans[i][j-1] == '^');
	friends += ((i-1) >= 0 && ans[i-1][j] == '^');
	if(friends < 2 && grid[i][j] == '^'){
		cond = false;
		return;
	}
	if(friends < 2){
		ans[i][j] = '.';
		work(i-1, j, ii, jj);
		work(i, j-1, ii, jj);
		work(i, j+1, ii, jj);
	}
}
void solve(){
	int tt;
	cin >> tt;
	For(t, tt){
		cin >> r >> c;
		grid.resize(r);
		ans.resize(r);
		For(i, r){
			cin >> grid[i];
		}
		For(i, r){
			string s = "";
			For(j, c){
				if(grid[i][j] == '#'){
					s += "#";
				}else{
					s += '^';
				}
			}
			ans[i] = s;
		}
		cond = true;
		For(i, r){
			For(j, c){
				if(ans[i][j] == '^'){
					work(i, j, i, j);
				}
			}
		}
		if(!cond){
			cout << "Case #" << (t+1) << ": Impossible" << endl;
			continue;
		}
		cout << "Case #" << (t+1) << ": Possible" << endl;
		For(i, r){
			cout << ans[i] << endl;
		}

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
