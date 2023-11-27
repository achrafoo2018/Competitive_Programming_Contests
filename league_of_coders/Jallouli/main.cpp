#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi 3.141592653589793
using namespace std;

const ll N = 1e6+7;
int main() {
    ll h,w,n; cin >> h >> w >> n;
    ll nb[h+1][w+1];
    memset(nb, 0, sizeof nb);
    ll p[n];
    pair<ll,ll> c[n];
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (ll i = 0; i < n; i++) {
        ll x,y; cin >> x >> y;
        x--; y--;
        c[i] = {x,y};
    }
    for (ll i = 0; i < 2; i++) {
        set<pair<ll,ll>> vis;
        vector<pair<ll,ll>> v = {c[i]};
        ll val = 0;
        while (! v.empty() && val < 2000009) {
            val+= p[i];
            vector<pair<ll,ll>> aux;
            for (auto [a,b] : v) {
                vis.insert({a,b});
                if (a >= 0 && b >= 0 && a < h && b < w)
                    nb[a][b]++;
            }
            for (auto [a,b] : v) {
                bool ok = false;
                for (ll j = 0; j <= val; j++) {
                    ll dx = j;
                    ll dy = val-j;
                    bool bb = false;
                    for (ll t = -1; t <= 1; t+= 2) {
                        for (ll y = -1; y <= 1; y+= 2) {
                            ll newA = a+dx*t;
                            ll newB = b+dy*y;
                            if (newA >= 0 && newB >= 0 && newA < h && newB < w) {
                                bb = true;
                                if (! vis.count({newA, newB})) {
                                    vis.insert({newA, newB});
                                    aux.emplace_back(newA, newB);
                                    bb = true;
                                }
                            }
                        }
                    }
                }
            }
            aux.swap(v);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            if (nb[i][j] == n)
                ans++;

        }
    }
    cout << ans;

}
