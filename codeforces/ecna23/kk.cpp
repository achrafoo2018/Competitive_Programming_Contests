#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;


int main() {
    int n; cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    map<tuple<string,string,int>, set<pair<int,int>>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int sz1 = (int) s[i].size();
            int sz2 = (int) s[j].size();
            if (sz1 != sz2)
                continue;
            vector<int> v;
            string s1,s2;
            for (int k = 0; k < sz1; k++) {
                if (s[i][k] != s[j][k]) {
                    v.push_back(k);
                    s1+= s[i][k];
                    s2+= s[j][k];
                }
            }
            if (v.size() == 2) {
                if (v[0]+1 == v[1]) {
                    if (s1 > s2)
                        swap(s1, s2);
                    st[{s1,s2,v[0]}].insert({i,j});
                }
            }
        }
    }
    int ans = 0;
    for (auto [a,b] : st) {
        if (b.size() == 1)
            ans++;
    }
    cout << ans;
}

