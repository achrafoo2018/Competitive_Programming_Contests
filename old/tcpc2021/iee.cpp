#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int c, n;
        cin >> c >> n;
        vector<pair<int, int>> vpi;
        for(int i=0; i < n; i++){
            int w, f;
            cin >> w >> f;
            vpi.push_back(make_pair(w, f));
        }
        bool visited[1000];
        memset(visited, false, sizeof visited);
        sort(vpi.begin(), vpi.end(), greater<pair<int, int>>());
        int cw = c, ans = 0;
        for(int i=0; i < n; i++){
            int mi = -1;
            double fi = -1e5;
            for(int j=0; j < n; j++){
                if(visited[j])
                    continue;
                double cf = (vpi[j].second / (double) vpi[j].first);
                if(cf > fi && vpi[j].first <= cw){
                    fi = cf;
                    mi = j;
                    visited[j] = true;
                }
            }
            if(mi == - 1)
                break;
            ans += vpi[mi].second;
            cw -= vpi[mi].first;       
        }
        cout << ans << endl;
    }
    return 0;
}