#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());


ll x, y, t;

ll brute_force() {
    ll nb = 1000000;
    ll mn = LLONG_MAX;
    ll ans = LLONG_MAX;
    for (ll i = 1; i <= nb; i++) {
        ll d = i*x+(i-1)*y;
        if (abs((2*i-1)*t-d) < mn) {
            ans = i;
            mn = abs((2*i-1)*t-d);
        }
    }
    return 2*ans-1;
}


ll f(ll i) {
    return abs(x*i+y*(i-1)-(2*i-1)*t);
}

ll ternary_search(ll l, ll r) {
    //set the error limit here
    while (r - l > 2) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(m1);		//evaluates the function at m1
        ll f2 = f(m2);		//evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    ll res = l;
    for (ll i = max(l-1000, 1LL); i <= (r+1000); i++) {
        if (f(i) < f(res))
            res = i;
    }
    return res;					//return the maximum of f(x) in [l, r]
}

int main() {
    ll T; cin >> T;
    while (T--) {
        cin >> x >> y >> t;
        ll l = 1, r = 1e7;
        ll res = ternary_search(l,r);
        ll pp = f(res);
        ll xx = abs(x+y - 2*t);
        if(xx <= pp){
            cout << 2 << "\n";
            continue;
        }
        cout << 2*res-1 << '\n';
    }
}