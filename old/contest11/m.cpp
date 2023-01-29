#include "bits/stdc++.h"
 
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

void solve(){
	freopen("lis.in", "r",stdin);
	string n;
	cin >> n;
	int s=0;
	for(char i:n)
		if(i == '9')
			s++;
	if(s == n.size())
		cout << 9 * n.size() << endl;
	else{
		int ans = 0;
		ans += (n.size() - 1) * 9;
		ans += (int)n[0] - 49;
		cout << ans << endl;
	}
}

int main(){
	fastio;
	solve();
	return 0;
}
