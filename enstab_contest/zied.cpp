//============================================================================
// Name        : Brahmi Zied
// Author      : brahZied
// Version     : 2022
// Description : Road to expert
//============================================================================
/*
    STAY ORGANIZED
    CHANGE YOUR APPROACH
    BE CONFIDENT
*/
// when you train write the algos from 0
//Think different approaches 
//(trace TestCase,think with symbols,think with PICS,
//numberTheory,bs,dp,greedy,graphs,shortest paths,mst,
//dsu,LCA(binary lifting?),hashing(strings))
//Stay Calm
// IN TRAINING DO NOT SEE WRONG TEST CASES AFTER SUBMITTING!
//Look for special cases
//Beware of overflow and array bounds
//Think the problem backwards
#include <bits/stdc++.h>
using namespace std;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;
typedef long double ld;
ll n,m,g,d,c;
const ll prime=1e9+7;
const ll prime2=998244353;
const ll prime3=7901;

void solve(string s){
    stack<char> st;
    n=(int)s.size();
    int indx=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            indx++;
        }else{
            indx--;
        }
        if(indx < 0){
            cout << "NO" << endl; return;
        }
    }
    if(indx!=0){
                cout << "No"<<'\n';
                return;
    }
    string rez="";
    ll longest=0;
	for(int i=0;i<(1<<n);i++){
        string ss="";
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                ss+=s[j];
            }
        }
        string temp=ss;
        reverse(ss.begin(),ss.end());
        if(temp==ss){
            longest=max(longest,(ll)temp.size());
        }
    }
    cout << longest<<'\n';
}
	
 
int main() {
	fastInp;
	//freopen("t.out","w",stdout);
	int tc=1;
	//debug() << imie(sieve);
	//cin >> tc;
	//cout << setprecision(10)<<fixed;
	while(tc--){
     //   string s="(((((()()()(()()()()))))))";
        string s="()(((((((((((())))))))))))";
		solve(s);
		
	}

	return 0;
}
