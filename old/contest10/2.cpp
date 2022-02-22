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

const int N = 1000;
int arr[N][5];
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=0; i < n;i++)
			for(int j=0; j < 5; j++)
				cin >> arr[i][j];
		int fg, sg;
		bool vs[n];
		memset(vs, false, sizeof(vs));
		for(int i=0; i < 5;i++){
			int k = 0;
			bool vs2[n];
			memset(vs2, false, sizeof(vs2));
			for(int j=0; j < n; j++){
				if(k == n/2)
					break;
				if(arr[j][i] == 1){
					if(!vs[j]){
						k++;
						vs2[j] = true;
					}else{

					}
				}
			}
			if(k == n / 2){
				for(int m=0; m < n; m++){
					if(vs2[m] == true){
						vs[m] = true;
					}
				}
			}
		}
		int k;
		for(k = 0; k < n; k++){
			if(vs[k] == false)
				break;
		}
		if(k < n){
			memset(vs, false, sizeof(vs));
			for(int i=4; i >= 0;i--){
				int k = 0;
				bool vs2[n];
				memset(vs2, false, sizeof(vs2));
				for(int j=0; j < n; j++){
					if(k == n/2)
						break;
					if(arr[j][i] == 1){
						if(!vs[j]){
							k++;
							vs2[j] = true;
						}else{
							
						}
					}
				}
				if(k == n / 2){
					for(int m=0; m < n; m++){
						if(vs2[m] == true){
							vs[m] = true;
						}
					}
				}
			}
			for(k = 0; k < n; k++){
				if(vs[k] == false)
					break;
			}
		}
		if(k == n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
	return 0;
}
