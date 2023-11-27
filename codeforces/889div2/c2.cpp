#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define endl '\n';
#define yes cout << "YES\n";
#define no  cout << "NO\n";
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

int n;
vpii arr;
vi a;

void solve(){
	cin >> n;
	arr.resize(n);
	a.resize(n);
	For(i, n){
		cin >> arr[i].first;
		arr[i].second = (i+1);
		a[i] = arr[i].first;
	}
	sort(all(arr));
	if(arr[n-1].first == arr[0].first){
		cout << 0 << endl; return;
	}	
	vpii ans;
	if(arr[0].first < 0){
		for(int j=-100; j <= 0; j++){
			ans.clear();
			int i = n-1;
			ll x = a[i];
			ll xx = arr[0].first;
			int l = 0;
			while(x > j){
				x += xx;
				ans.PB({i+1, arr[0].second});
				l++;
				if(l == 3) break;
			}
			if(l == 3){
				xx += x;
				ans.PB({arr[0].second, i+1});
			}
			int turn = 0;
			while(x > j){
				x += xx;
				ans.PB({i+1, arr[0].second});
			}
			i--;
			bool cond = 1;
			while(i >= 0){
				ll y = a[i];
				while(y > x ){
					y += x;
					ans.PB({i+1, i+2});
					if(ans.size() > 31){
						cond = 0; break;
					}
				}
				if(ans.size() > 31){
					cond = 0; 
					break;
				}
				x = y;
				i--;
			}
			if(cond && ans.size() <= 31){

				cout << ans.size() << endl;
				for(auto i : ans){
					cout << i.first << " " << i.second << endl; 
				}
				return;
			}
			debug() << imie(ans.size());
		}
	}
	if(arr[n-1].first > 0){
		For(j, 100){
			ans.clear();
			int i = 0;
			ll x = a[i];
			ll xx = arr[n-1].first;
			int l = 0;
			while(x < j){
				x += xx;
				ans.PB({i+1, arr[n-1].second});
				l++;
				if(l == 3) break;
			}
			if(l == 3){
				xx += x;
				ans.PB({arr[n-1].second, i+1});
			}
			int turn = 0;
			while(x < j){
				x += xx;
				ans.PB({i+1, arr[n-1].second});
			}
			i++;
			bool cond = 1;
			while(i < n){
				ll y = a[i];
				while(y < x){
					y += x;
					ans.PB({i+1, i});
					if(ans.size() > 31){
						cond = 0; break;
					}
				}
				if(ans.size() > 31){
					cond = 0;
					 break;
				}
				x = y;
				i++;
			}
			if(cond && ans.size() <= 31){
				cout << ans.size() << endl;
				for(auto i : ans){
					cout << i.first << " " << i.second << endl; 
				}
				return;
			}
		}
	}
	assert(false);
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}