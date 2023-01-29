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
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

string x;
string removeKdigits(string num, int k)
{
    int n = num.size();
    stack<char> mystack;
    for (char c : num) {
        while (!mystack.empty() && k > 0
               && mystack.top() > c) {
            mystack.pop();
            k -= 1;
        }
 
        // if (!mystack.empty())
		mystack.push(c);
	}
 
    while (!mystack.empty() && k--){
        mystack.pop();
	}
    while (!mystack.empty()) {
        num[n - 1] = mystack.top();
        mystack.pop();
        n -= 1;
    }
	string res = num.substr(n);
	if(res == "0"){
		char mn = '9';
		for(char c : x ) {
			if(c == '0') continue;
			mn = min(mn, c);
		}
		string ret = "";
		ret += mn;
		return ret;
	}
	if(res[0] == '0'){
		int i = x.size()-1;
		int nb0 = count(all(x), '0');
		while(i >= 0){
			if(x[i] == '0'){
				nb0--;
			}
			if(nb0 == 0) break;
			i--;
		}
		char mn='9';
		while(i > 0){
			i--;
			if(x[i] == '0') continue;
			mn = min(mn, x[i]);
		}
		int skip = 0;
		for(int i=0; i < res.size() - 1; i++){
			if(res[i] > res[i+1]){
				skip = i;
				break;
			}
		}
		string ret = "";
		ret += mn;
		For(i, res.size()){
			if(i == skip) continue;
			ret += res[i];
		}
		return ret;
	}
    return num.substr(n);
}

void solve(){
	cin >> x;
	int k; cin >> k;
	cout << removeKdigits(x, k) << endl;;
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
