#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)


float roundd(float var){
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

void solve(){
	ofstream myfile;
	myfile.open("bad.out");
	int n, m;
	cin >> n >> m;
	map<string, int> presidents;
	vector<string> pres(n);
	vector<pair<int, string>> arr(n);
	For(i, n){
		cin >> arr[i].second;
		presidents[arr[i].second] = i;
		pres[i] = arr[i].second;
	}
	int inv = 0;
	For(i, m){
		string s;
		cin >> s;
		int nb_X = count(all(s), 'X');
		if(nb_X > 1 || nb_X == 0){
			inv++;
			continue;
		}
		int pos = -1;
		For(j, n){
			if(s[j] == 'X'){
				pos = j;
				break;
			}
		}
		arr[pos].first++;
	}
	sort(all(arr));
	map<int, vi> mp;
	for(auto i: arr){
		mp[i.first].push_back(presidents[i.second]);
	}
	vector<pair<int, vector<string>>> res;
	for(auto i: mp){
		sort(all(i.second));
		vector<string> vvvs;
		for(auto idx : i.second)
			vvvs.push_back(pres[idx]);
		res.push_back(make_pair(i.first, vvvs));
	}
	sort(all(res));
	debug() << imie(res);
	myfile << setprecision(2);
	myfile << fixed;

	for(int i=res.size()-1; i >= 0; i--){
		for(int j=0; j < res[i].second.size(); j++){
			myfile << res[i].second[j] << " " << roundd(((res[i].first * 100 ) / (float)m)) << "%" << endl;
		}
	}
	myfile << "Invalid " << roundd((inv * 100 ) / (float)m) << "%" << endl;
}

int main(){
	fastio;
	freopen("bad.in", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
