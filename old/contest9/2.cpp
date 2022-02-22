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


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		ll a[n];
		ll b[n];
		for(int i=0; i < n;i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b+n);
		int i;
		for(i = n - x; i < x; i++){
			if(a[i] != b[i])
				break;
		}
		if(i >= x){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}	
	return 0;
}
