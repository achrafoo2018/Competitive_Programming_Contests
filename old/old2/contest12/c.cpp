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

const int N = 1e5+6;
vvi graph(N);
vector<bool> visited(N, false);
int arr[3] = {2, 5, 11};
void bfs(){
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int i = 0;
	while(!q.empty()){
		int x = q.back();
		q.pop();
		cout << arr[i] << " ";
		i++;
		for(auto i : graph[x]){
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
void solve(){
		int n;
		cin >> n;
		For(i, n-1){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		debug() << imie(graph[1]);
		For(i, n){
			if(graph[i].size() > 2){
				cout << -1 << endl;
				return;
			}
		}
		// bfs();
	
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
