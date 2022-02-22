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


const int N=1e5+7;
int a[N], b[N];
void solve(){
	int n;
	cin >> n;
	vector<pii> v, v2;
	For(i, n){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(all(v));
	For(i, n){
		if(v[i].first < v[i+1].first && v[i].second > v[i+1].second){
			cout << "Happy Alex" << endl;
			return;
		}
	}
	cout << "Poor Alex" << endl;
	
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
