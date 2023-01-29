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
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

vector<vector<pair<string, int>>> arr(5);
int B;
int P, G, S, F, C;
pair<string, ll> answer;
unordered_map<int, unordered_map<ll, bool>> dp;
void work(){
	For(i, arr[0].size()){
		if(arr[0][i].second > B)
			continue;
		For(j, arr[1].size()){
			if(dp[1][arr[0][i].second])
				break;
			if(arr[0][i].second + arr[1][j].second > B)
				continue;
			For(k, arr[2].size()){
				if(dp[2][arr[0][i].second + arr[1][j].second])
					break;
				if(arr[0][i].second + arr[1][j].second + arr[2][k].second > B)
					continue;
				For(l, arr[3].size()){
					if(dp[3][arr[0][i].second + arr[1][j].second + arr[2][k].second])
						break;
					if(arr[0][i].second + arr[1][j].second + arr[2][k].second + arr[3][l].second > B)
						continue;
					For(m, arr[4].size()){
						if(dp[4][arr[0][i].second + arr[1][j].second + arr[2][k].second + arr[3][l].second])
							break;
						
						if(arr[0][i].second + arr[1][j].second + arr[2][k].second + arr[3][l].second + arr[4][m].second <= B){
							ll res = arr[0][i].second + arr[1][j].second + arr[2][k].second + arr[3][l].second + arr[4][m].second;
							string names = arr[0][i].first + "\n" + arr[1][j].first + "\n"
									+ arr[2][k].first + "\n" + arr[3][l].first + "\n" + arr[4][m].first + "\n";
							if(res > answer.second){
								answer = {names, res};
							}else if(res == answer.second){
								answer.first = min(names, answer.first);
							}
						}
					}
					dp[4][arr[0][i].second + arr[1][j].second + arr[2][k].second + arr[3][l].second] = 1;
				}
				dp[3][arr[0][i].second + arr[1][j].second + arr[2][k].second] = 1;
			}
			dp[2][arr[0][i].second + arr[1][j].second] = 1;
		}
		dp[1][arr[0][i].second] = 1;

	}
}
void solve(){
	cin >> B;
	int jj = 0;
	cin >> P;
	arr.clear();
	dp.clear();
	answer = {"", 0};
	For(i, P){
		string name; cin >> name;
		int x; cin >> x;
		arr[jj].push_back({name, x});
	}
	jj++;
	cin >> G;
	For(i, G){
		string name; cin >> name;
		int x; cin >> x;
		arr[jj].push_back({name, x});

	}
	jj++;
	cin >> S;
	For(i, S){
		string name; cin >> name;
		int x; cin >> x;
		arr[jj].push_back({name, x});
	}
	jj++;
	cin >> F;
	For(i, F){
		string name; cin >> name;
		int x; cin >> x;
		arr[jj].push_back({name, x});
	}
	jj++;
	cin >> C;
	For(i, C){
		string name; cin >> name;
		int x; cin >> x;
		arr[jj].push_back({name, x});
	}
	work();
	// debug() << imie(answer);
	cout << answer.first;
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

