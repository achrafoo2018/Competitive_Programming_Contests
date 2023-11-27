#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9+7;
const int N = 2e5+7;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    ll p2[N];
    p2[0] = 1;
    for (int i = 1; i < N; i++)
        p2[i] = (p2[i-1]*2)%mod;
    while (T--) {
        int n; cin >> n;
        int a[n];
        set<int> s;
        map<int,int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        ll p = 1;
        int sum = 0;
        ll ans = 0;
        for (int mex = 0; mex <= n; mex++) {
            sum+= cnt[mex];
            int rem = n-sum;
            ll cont = (p2[rem]+mod)%mod;
            cont = (cont*mex)%mod;
            cont = (cont*p)%mod;
            ans = (ans+cont)%mod;
            p = (p * (p2[cnt[mex]]-1+mod))%mod;
            if (cnt[mex] == 0)
                break;
        }
        cout << ans << '\n';
    }
}
