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

const int N = 107;
vvchr board(N, vchr(N));
int n;
bool visited[N][N];
vector<vpii> paths;
bool FindBoardStatusB(int i, int j, vpii path) {
	if(i >= n || i < 0)
		return 0;
	if(visited[i][j])
		return 0;
	if(j == n - 1){
		path.push_back({i, j});
		if(board[i][j] == 'B')
			paths.push_back(path);
		return board[i][j] == 'B';
	}
	visited[i][j] = 1;
	path.push_back({i, j});
	bool cond1 = board[i][j] == 'B' && FindBoardStatusB(i-1, j+1, path);
	bool cond2 = board[i][j] == 'B' && FindBoardStatusB(i-1, j, path);
	bool cond3 = board[i][j] == 'B' && FindBoardStatusB(i+1, j, path);
	bool cond4 = board[i][j] == 'B' && FindBoardStatusB(i+1, j+1, path);
	bool cond5 = board[i][j] == 'B' && FindBoardStatusB(i, j-1, path);
	bool cond6 = board[i][j] == 'B' && FindBoardStatusB(i+1, j-1, path);
	return (cond1 || cond2 || cond3);
}


bool FindBoardStatusR(int i, int j, vpii path) {
	if(j >= n || j < 0 )
		return false;
	if(visited[i][j])
		return 0;
	if(i == n-1){
		path.push_back({i, j});
		if(board[i][j] == 'R')
			paths.push_back(path);
		return board[i][j] == 'R';
	}
	visited[i][j] = 1;
	path.push_back({i, j});
	bool cond1 = board[i][j] == 'R' && FindBoardStatusR(i-1, j+1, path);
	bool cond2 = board[i][j] == 'R' && FindBoardStatusR(i-1, j, path);
	bool cond3 = board[i][j] == 'R' && FindBoardStatusR(i+1, j, path);
	bool cond4 = board[i][j] == 'R' && FindBoardStatusR(i+1, j+1, path);
	bool cond5 = board[i][j] == 'R' && FindBoardStatusR(i, j-1, path);
	bool cond6 = board[i][j] == 'R' && FindBoardStatusR(i+1, j-1, path);
	return (cond1 || cond2 || cond3 || cond4 || cond5 || cond6);
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
		For(i, N){
			For(j, N){
				visited[i][j] = 0;
			}
		}
		string winner = "";
		bool p1 = false;
		paths.clear();
		for(int i=0; i < n; i++){
			if(board[i][0] == 'B'){
				if(!p1)
					p1 = FindBoardStatusB(i, 0, vpii());
				else{
					FindBoardStatusB(i, 0, vpii());
				}
			}
		}

		bool impossible = false;
		for(int i=0; i < paths.size(); ++i){

			for(int k=0; k < paths.size(); k++){
				if(k == i)
					continue;
				bool found = false;
				for(int j=0; j < paths[i].size(); j++){
					for(int m=0; m < paths[k].size(); m++){
						if(paths[k][m].first == paths[i][j].first && paths[k][m].second == paths[i][j].second){
							found = true;
							goto skip;
						}
					}
				}
				skip:
				if(!found){
					impossible = true;
					goto next;
				}
			}

		}
		next:
		if(impossible){
			cout << "Case #" << tc << ": " << "Impossible" << endl;
			continue;

		}
		bool p2 = false;
		paths.clear();
		For(i, N){
			For(j, N){
				visited[i][j] = 0;
			}
		}

		for(int i=0; i < n; i++){
			if(board[0][i] == 'R'){
				if(!p2)
					p2 = FindBoardStatusR(0, i, vpii());
				else{
					FindBoardStatusR(0, i, vpii());
				}
			}
		}

		impossible = false;
		for(int i=0; i < paths.size(); ++i){
			for(int k=0; k < paths.size(); k++){
				if(k == i)
					continue;
				bool found = false;
				for(int j=0; j < paths[i].size(); j++){
					for(int m=0; m < paths[k].size(); m++){
						if(paths[k][m].first == paths[i][j].first && paths[k][m].second == paths[i][j].second){
							found = true;
							goto skip2;
						}
					}
				}
				skip2:
				if(!found){
					impossible = true;
					goto next2;
				}
			}
		}
		next2:
		if(impossible){
			cout << "Case #" << tc << ": " << "Impossible" << endl;
			continue;

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
	// int t = 1;
	// // cin >> t;
	// while(t--)
		solve();
	return 0;
}