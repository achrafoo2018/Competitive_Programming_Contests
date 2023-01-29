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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		For(i, n)
			cin >> a[i];
		int l = 1, r = n - 2;
		int res[n];
		if(a[0] > a[n-1]){
			res[n-1] = a[0];
			int i;
			for(i=1; i < n; i++){
				res[n-i-1] = a[i];
				if(a[i] > res[n-1])
					break;
			}
			if(i < n)
				cout << -1 << endl;
			else{
				for(auto i:res)
					cout << i << " ";
				cout << endl;
			}
		}else{
			res[n-1] = a[n-1];
			int i;
			for(i=0; i < n-1; i++){
				res[n-i-2] = a[i];
				if(a[i] > res[n-1])
					break;
			}
			if(i < n-1)
				cout << -1 << endl;
			else{
				for(auto i:res)
					cout << i << " ";
				cout << endl;
			}
		}
		
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
