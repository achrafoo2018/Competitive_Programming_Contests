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
		ll n, H;
		cin >> n >> H;
		ll max1 = -1, max2= -1;
		for(int i=0; i < n; i++){
			int x;
			cin >> x;
			if(x > max1) {
				max2 = max1;
				max1 = x;
			} else if (x > max2) {
				max2 = x;
			}
		}
		int ans = 0;
		if(max1 >= H)
			cout << 1 << endl;
		else{
			int ans = (H / (max1+max2)) * 2;
			if(H % (max1+max2) == 0)
				cout << ans << endl;
			else if(H % (max1+max2) <= max1){
				cout << ans + 1 << endl;
			}else
				cout << ans + 2 << endl;
		}
	}	
	return 0;
}
