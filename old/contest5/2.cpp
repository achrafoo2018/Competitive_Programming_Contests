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
		string players;
		cin >> players;
		int i, j;
		char arr[n][n];
		memset(arr, 'k', sizeof arr);
		for(i=0; i < n; i++){
			int wins = 0;
			for(j=0; j < n; j++){
				if(arr[i][j] != 'k')
					continue;
				if(i == j){
					arr[i][j] = 'X';
					continue;
				}
				if(players[i] == '1'){
					arr[i][j] = '=';
					arr[j][i] = '=';
				}else{
					if(players[j] == '2' && wins == 0){
						arr[i][j] = '+';
						arr[j][i] = '-';
						wins++;
					}else
						arr[i][j] = '=';
				}
			}
			if(players[i] == '2' && wins == 0){
				cout << "NO" << endl;
				break;
			}
		}
		if(i == n){
			cout << "YES" << endl;
			for(int i=0; i < n;i++){
				for(char c: arr[i])
					cout << c;
				cout << endl;
			}
		}
	}	
	return 0;
}
