#include "bits/stdc++.h"
/***************************************************/
/***************************************************/
/******************* 3ak3ek ************************/
/***************************************************/
/***************************************************/
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
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; i++)

vvi graph;
const int N=2*10e5+7;
bool visited[N];
void dfs(int pos){
	visited[pos] = true;
	cout << pos << endl;
	for(auto i:graph[pos]){
		if(!visited[i])
			dfs(i);
	}
}
void solve(){
	int t;
	cin >> t;
	set<int> friends;
	while(t--){
		int n, k;
		cin >> n >> k;
		graph.resize(n);
		For(i, k){
			int x;
			cin >> x;
			friends.insert(x);
		}
		For(i, n-1){
			int v, u;
			cin >> v >> u;
			graph[v].push_back(u);
			graph[u].push_back(v);
		}
		dfs(1);
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
