#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		int a[999];
		cin >> n;
		for(int i=0; i < n; i++){
			cin >> a[i];
		}
		int res = 0;
		int i=0;
		while(1){
			bool perm = false;
			for(int j=0 ; j < n-1; j++){
				if((i+1) % 2 != (j+1) % 2)
						continue;
				if(a[j] > a[j+1]){
					a[j] = a[j] + a[j+1];
					a[j+1] = a[j] - a[j+1];
					a[j] = a[j] - a[j+1];
					perm = true;
				}
			}
			if(!perm){
				bool sorted = true;
				for(int i=1; i < n; i++){
					if(a[i] < a[i-1]){
						sorted = false;
						break;
					}
				}
				if(sorted)
					break;
			}
			res++;
			i++;
		}
		cout << res << endl;
	}	
	return 0;
}
