#include<bits/stdc++.h>
using namespace std ;



void solve()
{ int n , a, b ;
bool ok ;
vector<pair<int , int>>v ;
    cin >> n ;
    for (int i=0 ; i<n ; i++)
    {
        cin >> a >> b ;
        v.push_back(make_pair(a,b)) ;
    }
    sort(v.begin(), v.end());
    int i=0 ;
    ok=false;
    while(i<n-1 && !ok)
    {
        if (v[i].first < v[i+1].first && v[i].second > v[i+1].second)
        {
            ok=true;
        }
        i++ ;
    }
    if (ok)
        cout<<"Happy Alex"<<endl ;
    else
        cout<<"Poor Alex"<<endl ;

}

int main()
{
solve() ;

}