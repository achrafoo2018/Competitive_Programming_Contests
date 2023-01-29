#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case #" << i << ": "


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(n == 1){
			cout << -1 << ' ' << -1 << endl;
			continue;
		}
		int i;
		for(i=0; i < s.size()-1; i++){
			if(s[i] != s[i+1]){
				cout << i+1 << ' ' << i+2 << endl;
				break;
			}
		}
		if (i == s.size() - 1 )
			cout << -1 << ' ' << -1 << endl;
	}	
	return 0;
}
