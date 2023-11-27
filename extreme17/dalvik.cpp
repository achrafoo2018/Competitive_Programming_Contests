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
#define no cout << "NO\n";
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                  \
  sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
  {
sim > struct rge
{
  c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug
{
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) cerr << boolalpha << i;
  ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c &) { ris; }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MP make_pair
#define PB push_back
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forr(i, n, p) for (int i = p; i < n; ++i)
#define dd(arr)                             \
  For(i, arr.size()) cout << arr[i] << " "; \
  cout << endl;

int work(int inputA, int inputB, int inputC) {
    int v0 = inputA;
    int v1 = inputB;
    int v2 = inputC;
    int v3 = 1;
    int v4 = 0;
    int v5 = -1;
    int v6 = 1;
    int v7 = -inputB;
    int v8 = inputA;
    int v9 = inputA + inputB;
    int v10 = 0;
    int v11 = 0;
    int v12 = 1;

    for (; v12 <= v2; v12++) {
        v11 += v1;
        v10 += v0;
        int v13 = v10;
        int v14 = 0;
        int v15 = 0;

        // Loop 1
        while (true) {
            int v16 = v13 + v13;
            if (v16 <= v1) {
                v13 -= v1;
                v14 += v3;
                v15 += v1;
            } else {
                break;
            }
        }

        if (v13 > v4) {
            v13 = v4 - v13;
        }

        int v17 = v4;
        int v18 = v3;

        // Loop 2
        while (v18 <= v6) {
            v17 += v13;
            v18 += v3;
        }

        v18 = v3;

        // Loop 3
        while (v18 <= v12) {
            v17 -= v9;
            v18 += v3;
        }

        if (v17 >= v4) {
            v5 = v14;
            v6 = v12;
            v7 = v15;
            v8 = v10;
            v9 = v13;
        }
    }

    return v6;
}


void solve()
{
  ll a, b, c;
  cin >> a >> b >> c;
  cout << work(a, b, c) << endl;
}

int main()
{
  fastio;
  // cout << setprecision(9);
  // cout << fixed;
  // freopen("input.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
