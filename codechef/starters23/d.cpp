#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
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


int maxMEX(vi arr, int N, int K){
    set<int> s;
    for (int i = 0; i <= N + 1; i++)
        s.insert(i);
    for (int i = 0; i < K; i++)
        s.erase(arr[i]);
 
    int mex = *(s.begin());
    for (int i = K; i < N; i++) {
        s.erase(arr[i]);
 
        s.insert(arr[i - K]);
        int firstElem = *(s.begin());
        mex = max(mex, firstElem);
    }
	return mex;
}

void solve(){
	int n, k, x;
	cin >> n >> k >> x;
	vi ans;
	int i = 0, j = x - 1, sze = 0;
	while(i < n){
		ans.push_back(j);
		sze++;
		if(j > 0)
			j--;
		if(sze % k == 0)
			j = x - 1;
		i++;
	}
	int mex = maxMEX(ans, n, k);
	if(mex != x)
		cout << -1 << endl;
	else{
		for(auto i : ans)
			cout << i << " ";
		cout << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
