// Mtaylor
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl '\n';
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
typedef long long ll;
const int N = 3e5 + 5;

int n;
ll k;
ll a[N];

bool ok(int p, ll u) {
    ll sm = 0;
    for (int j = p, c = 0; j < n; j++, c++) {
        ll cur = u - c;
        if (a[j] >= cur) break;
        if(j==n-1){
            sm+=1e9;
            break;
        }
        sm += (cur - a[j]);
    }
    return sm <= k;
}

void test_case() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        ll l = a[i];
        ll r = 1e9;
        while (l < r) {
            ll md = (l + r + 1) / 2;
            if (ok(i, md)) {
                l = md;
            } else {
                r = md - 1;
            }
        }
        ans = max(ans, l);
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        test_case();
    }
    return 0;
}
