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


vector<int> GetHIndexScore(vector<int> citations_per_paper) {
	vector<int> h_index;
	int ans = 1;
	unordered_map<int, int> mp;
	for(int i=0; i < citations_per_paper.size(); ++i){
		for(int j=1; j <= citations_per_paper[i]; j++)
			mp[j]++;
		if(mp[ans+1] >= ans+1)
			ans++;
		h_index.push_back(ans);
	}
  	return h_index;
}


void solve(){
	int tests;
	cin >> tests;
	for (int test_case = 1; test_case <= tests; test_case++) {
		// Get number of papers for this test case
		int paper_count;
		cin >> paper_count;
		// Get number of citations for each paper
		vector<int> citations(paper_count);
		for (int i = 0; i < paper_count; i++) {
			cin >> citations[i];
		}
		vector<int> answer = GetHIndexScore(citations);
		cout << "Case #" << test_case << ": ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
