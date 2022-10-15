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

const int N = 101;
vvchr board(N, vchr(N));
vvi dp(N, vi(N, -1));
int n;
vector<vector<vector<pii>>> paths;
bool FindBoardStatusB(int idx, int i, int j, vector<pii> path) {
	if(j == n){
		paths[idx].push_back(path);
		return true;
	}
	if(i >= n || j < 0 || i < 0)
		return false;
	if(dp[i][j] != -1)
		return dp[i][j];
	path.push_back({i, j});
	dp[i][j] = board[i][j] == 'B' && (FindBoardStatusB(idx, i, j+1, path) || FindBoardStatusB(idx, i+1, j+1, path) || FindBoardStatusB(idx, i-1, j+1, path));
	return dp[i][j];
}


bool FindBoardStatusR(int i, int j) {
	if(i == n)
		return true;
	if(j >= n || j < 0 )
		return false;
	return board[i][j] == 'R' && (FindBoardStatusR(i+1, j) || FindBoardStatusR(i+1, j+1) || FindBoardStatusR(i+1, j-1));
}


void solve(){
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		int B = 0, R = 0;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				cin >> board[r][c];
				if(board[r][c] == 'B')
					B++;
				else if(board[r][c] == 'R')
					R++;
			}
		}
		if(abs(R-B) > 1){
			cout << "Case #" << tc << ": " << "Impossible" << endl;
			continue;
		}
		string winner = "";
		bool p1 = false;
		For(i, N){
			For(j, N)
				dp[i][j] = -1;
		}
		paths.resize(n+1);
		for(int i=0; i < n; i++){
			if(board[i][0] == 'B')
				p1 = FindBoardStatusB(i, i, 0, vector<pii>());
		}
		debug() << imie(paths);
		if(p1){
			int c1 = 0, c2 = 0;
			for(int i=0; i < n; i++){
				if(board[i][0] == 'B')
					c1++;
				if(board[i][n-1] == 'B')
					c2++;
			}
			if(c1 > 1 && c2 > 1){
				cout << "Case #" << tc << ": " << "Impossible" << endl;
				continue;
			}
		}
		For(i, N){
			For(j, N)
				dp[i][j] = -1;
		}
		bool p2 = false;
		for(int i=0; i < n; i++){
			if(board[0][i] == 'R')
				p2 = FindBoardStatusR(0, i);
			if(p2)
				break;
		}
		if(p2){
			int c1 = 0, c2 = 0;
			for(int i=0; i < n; i++){
				if(board[0][i] == 'R')
					c1++;
				if(board[n-1][i] == 'R')
					c2++;
			}
			if(c1 > 1 && c2 > 1){
				cout << "Case #" << tc << ": " << "Impossible" << endl;
				continue;
			}
		}
		if(p1 && p2)
			winner = "Impossible";
		else if(p1)
			winner = "Blue wins";
		else if(p2)
			winner = "Red wins";
		else
			winner = "Nobody wins";
		cout << "Case #" << tc << ": " << winner << endl;
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
