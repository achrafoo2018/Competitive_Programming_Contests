#include<bits/stdc++.h>
using namespace std;
 
/*
// #pragma comment(linker, "/STACK:268435456");
#include <ext/pb_ds/assoc_container.hpp>
// // // Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, 
            rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set; 
*/
//========================TypeDefs===================================//
 
typedef long long ll;
typedef unsigned long long int ull;
typedef long double ldb;
 
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
 
 
//=========================MACROS====================================//
 
// using vl = vector<ll>;
// using vvl = vector<vl>;
 
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mll map<ll,ll>
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define le length()
#define be begin()
#define en end()
 
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define reprev(i,n) for(ll i=n-1;i>=0;i--)
#define reprev1(i,n) for(ll i=n;i>0;i--)
#define repm(i,m,n) for(ll i=m;i<n;i++)
#define repmrev(i,m,n) for(ll i=n-1;i>=m;i--)
 
#define PN cout<<"NO\n"
#define PY cout<<"YES\n"
 
 
const int inf=INT_MAX;
const long long mod=1e12;
const int N=2e5+1;
 
 
//=========================FUNCTIONS====================================//
 
/*
FINDING A POWER N WITHOUT MODULO OPERATION
 
ll binpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(a & 1){
            res=res*a;
        }
        a=a*a;
        b >>=1;
    }
    return res;
}
*/
 
/*
FINDING A POWER N MODULO M
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
*/
 
 
//SORTING BY SECOND VALUE
/*
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second>b.second);
}
*/
/*
RETURNS WHETHER A NUMBER IS PRIME
 
bool isprime(ll n){
    if(n==1){
        return false;
    }
    ll i=2;
    while(i*i<=n){
        if(n%i==0){
            return false;
        }
        i++;
    }
    return true;
}
*/
/*
//SUM OF DIVISORS
int divisors(ll n){
    ll sum=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            sum+=i;
            if(n%(n/i)==0 && i!=n/i){
                sum+=(n/i);
            }
        }
    }
    return sum;
}
*/
/*
RETURNS GCD OF TWO NUMBERS
 
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
*/
 
/*
//DFS
void dfs(int node){
    vis[node]=1;
    cc[node]=cnt;
    for(int child:arr[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }
}
*/
/*
//BFS
void bfs(int node){
    queue<int> q;
    vis[node]=1;
    q.push(node);
    dist[node]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int child:arr[curr]){
            if(vis[child]==0){
                dist[child]=dist[curr]+1;
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
//Maximum prime divisor of a number
ll maxPrime(ll n){
    ll mp=-1;
    while(n%2==0){
        mp=2;
        n>>=1;
    }
    while(n%3==0){
        mp=3;
        n/=3;
    }
    for(ll i=5;i*i<=n;i++){
        while (n % i == 0) {
            mp = i;
            n = n / i;
        }
        while (n % (i+2) == 0) {
            mp = i+2;
            n = n / (i+2);
        }
    }
    if(n>4){
        mp=n;
    }
    return mp;
}
 
 
ll power(ll a,ll b)
{
    if(a==1||b==0)  return 1;
    ll c=power(a,b/2);
    ll res=1;
    res=c*c;
    if(res>=mod)    res%=mod;
    if(b%2) res*=a;
    if(res>=mod)    res%=mod;
    return res;
}
 
*/
 
 //char alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l',
//    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
 
//=========================MAIN====================================//
ll power(ll a,ll b)
{
    if(a==1||b==0)  return 1;
    ll c=power(a,b/2);
    ll res=1;
    res=c*c;
    if(b%2) res*=a;
    return res;
}


void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll n=a*b;
    unordered_map<ll,ll> mp;
    ll cnt=0;
    while(n%2==0){
        cnt++;
        n/=2;
    }
    mp[2]=cnt;
    for(ll i=3;i*i<=n;i+=2){
        cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        mp[i]=cnt;
    }
    if(n>1){
        mp[n]=1;
    }
    unordered_map<ll,ll> mp1;
    for(ll i=a+1;i<=c;i++){
        n=i;
        cnt=0;
        while(n%2==0){
            cnt++;
            n/=2;
        }
        mp1[2]=cnt;
        for(ll i=3;i*i<=n;i+=2){
            cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            mp1[i]=cnt;
        }
        if(n>1){
            mp1[n]=1;
        }
        ll p=1;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(mp1.find(it->first)!=mp1.end()){
                if(it->second>mp1[it->first]){
                    p*=power(it->first,it->second-mp1[it->first]);
                }
            }else{
                p*=power(it->first,it->second);
            }
        }
        //cout<<i<<" "<<p<<"\n";
        ll x=(d/p);
        x*=p;
        p=x;
        //cout<<p<<"\n";
        if(p<=d && p>b && (p*i)%(a*b)==0){
            cout<<i<<" "<<p<<"\n";
            return;
        }
        mp1.clear();
    }
    cout<<-1<<" "<<-1<<"\n";
}
 
int main(){
    # // freopen("input.txt","r",stdin);
    # // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}