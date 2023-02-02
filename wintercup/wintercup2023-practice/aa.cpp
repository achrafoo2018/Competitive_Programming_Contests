#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <math.h>

typedef long long ll ;

#define pairi pair <int,int>
#define pairll pair <long long,long long>
#define vi vector <int> 
#define vll vector <long long> 
#define mapi map <int,int> 
#define mapill map <int,long long> 
#define seti set <int> 
#define setll set <long long> 
#define pb push_back
#define fr(i,a,b) for(int i = a ; i < b ; i++)
#define fir(i,a,b) for(int i = b ; i >= a ; i--)
#define tarr(a,n,typ,val) typ *a = new typ[n] ; fr(i,0,n) a[i] = val
#define arr(a,n,val) tarr(a,n,int,val)
#define tmatrix(M,n,m,typ) typ**M = new typ*[n] ; fr(i,0,n) M[i] = new typ[m]
#define matrix(M,n,m) tmatrix(M,n,m,int)
#define outA(a,n) fr(_,0,n) cout << (a)[_] << " " ; cout << endl 
#define outM(M,n,m) fr(__,0,n) { outA((M)[__],m) ; }
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define yes(check) cout << (check ? "YES" : "NO") << endl

using namespace std;

int main()
{
    fast ;
    // #warning TODO : comment out freopen
    // freopen("in","r",stdin) ;
    // freopen("out","w",stdout) ;
    int t , n , i , j , k , x , y ;
    cin >> t ;
    while(t--)
    {
        string s ;
        cin >> s ;
        n = s.size() ;
        i = s.size()-2 ;
        while(i>=0){
            if(s[i] > s[i+1])
                break ;
            i -- ;
        }
        if(i < 0 )
            cout << -1 << endl ;
        else{
            string ans = "" ;
            fr(j,0,i){
                if(j!=i)
                    ans += s[j] ;
                else{
                    break ;
                }           
            }
            string temp ;
            // temp += s[i] ;
            fr(k,i+1,n)
                temp += s[k] ;
            // cout << temp << "  here  " << endl ;
            sort(temp.begin(),temp.end()) ;
            reverse(temp.begin(),temp.end());
            ans += temp[0] ;
            // cout << s << endl ;
            // cout << i << " " << s[i] << endl ;
            temp[0] = s[i] ;
            sort(temp.begin(),temp.end()) ;
            reverse(temp.begin(),temp.end());
            ans += temp ;
            cout << ans << endl ;
        }
    }

}