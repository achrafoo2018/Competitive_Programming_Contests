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

void solve(){
	int n;
	cin >> n;
	vi pos, neg;
	For(i, n){
		int x;
		cin >> x;
		if(x >= 0)
			pos.push_back(x);
		else
			neg.push_back(x);
	}
	sort(all(neg));
	sort(all(pos));
	if(neg.size())
		cout << "Neg : ";
	For(i, neg.size())
		cout << neg[i] << " ";
	if(neg.size())
		cout << endl;
	if(pos.size())
		cout << "Pos : ";
	For(i, pos.size())
		cout << pos[i] << " ";
	if(pos.size())
		cout << endl;

}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
