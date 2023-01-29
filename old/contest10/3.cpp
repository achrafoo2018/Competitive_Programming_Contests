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

const int N = 1e5*2 + 7;
int arr[N];
int fact(int n){
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r){
    return fact(n) / (fact(r) * fact(n - r));
}
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll somme = 0;
		for(int i=0; i < n; i++){
			cin >> arr[i];
			somme += arr[i];
		}
		double mean = somme / (double)n;
		sort(arr, arr+n);
		if(arr[0] == arr[n-1]){
			cout << nCr(n, 2) << endl;
			continue;
		}
		int r=n-1, l=0;
		int res = 0;
		while(l < r){
			double ans = (arr[l] + arr[r]) / 2.0;
			if( ans == mean){
				res++;
				l += 1;
				r -= 1;
			}else if(ans < mean)
				l++;
			else
				r--;
		}
		cout << res << endl;
	}	
	return 0;
}
