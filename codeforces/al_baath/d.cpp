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

#define INT_SIZE 32

int k;


const int N = 1e5+7;
int arr[N];
long long subarrayXor(int arr[], int n, int m)
{
    long long ans = 0; // Initialize answer to be returned
 
    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    int* xorArr = new int[n];
 
    // Create map that stores number of prefix array
    // elements corresponding to a XOR value
    unordered_map<int, int> mp;
 
    // Initialize first element of prefix array
    xorArr[0] = arr[0];
 
    // Computing the prefix array.
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];
 
    // Calculate the answer
    for (int i = 0; i < n; i++) {
       
        // Find XOR of current prefix with m.
        int tmp = m ^ xorArr[i];
 
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        ans = ans + ((long long)mp[tmp]);
 
        // If this subarray has XOR equal to m itself.
        if (xorArr[i] == m)
            ans++;
 
        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }
 
    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
}

int occ[1030];
int occ2[1030];

void solve(){
    int n; cin >> n >> k;
    memset(occ, 0, sizeof(occ));
    memset(occ2, 0, sizeof(occ2));
	vector<int> v;
    For(i, (1 << 10)){
        int ps = 0;
        For(pp, 10){
            ps += ((i >> pp) & 1);
        }
        if(ps == k)
            v.push_back(i);
     }
    For(i, n) cin >> arr[i];
    int x = 0;
	For(i, n){
        x ^= arr[i];
        occ[x] = 1;
    }
    For(i, 1024){
        if(!occ[i]) continue;
        For(j, 1024){
            if(!occ[j]) continue;
            occ2[i ^ j]++;
        }
    }
	int ans = 0;
    For(i, 1024){
		if(!occ[i] && !occ2[i]) continue;
        for(auto p : v){
            ans = max(ans, i ^ p);
        }
        ans = max(ans, i);
	}
    cout << ans << endl;
}

int main(){
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}