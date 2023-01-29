#include "bits/stdc++.h"
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
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
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)

vi likeArr;
vi dislikeArr;
vstr ingredients;
unordered_map<string, int> allIngredients;
vector<pair<vstr, vstr>> clients;
unordered_set<string> ans;

int getScore(){
	int score = 0;
	for(auto client : clients){
		bool isClient = true;
		for(auto ingredient : client.first){
			if(ans.find(ingredient) == ans.end()){
				isClient = false;
				break;
			}
		}
		for(auto ingredient : client.second){
			if(ans.find(ingredient) != ans.end()){
				isClient = false;
				break;
			}
		}
		score += isClient;
	}
	return score;
}

void solve(){
	int C;
	cin >> C;
	int ingredientsCounter = 1;
	For(i, C){
		int L;
		cin >> L;
		clients.push_back({vstr(), vstr()});
		For(j, L){
			string ingredient;
			cin >> ingredient;
			clients[i].first.push_back(ingredient);
			if(allIngredients.find(ingredient) != allIngredients.end()){
				likeArr.push_back(allIngredients[ingredient]);
			}else{
				allIngredients[ingredient] = ingredientsCounter;
				likeArr.push_back(ingredientsCounter++);
			}
		}
		int D;
		cin >> D;
		For(j, D){
			string ingredient;
			cin >> ingredient;
			clients[i].second.push_back(ingredient);
			if(allIngredients.find(ingredient) != allIngredients.end()){
				dislikeArr.push_back(allIngredients[ingredient]);
			}else{
				allIngredients[ingredient] = ingredientsCounter;
				dislikeArr.push_back(ingredientsCounter++);
			}
		}
	}
	sort(all(likeArr));
	sort(all(dislikeArr));
	for(auto ingredient : allIngredients){
		int nbLikes = (upper_bound(all(likeArr), ingredient.second) - likeArr.begin()) - (lower_bound(all(likeArr), ingredient.second) - likeArr.begin());
		int nbDislikes = (upper_bound(all(dislikeArr), ingredient.second) - dislikeArr.begin()) - (lower_bound(all(dislikeArr), ingredient.second) - dislikeArr.begin());
		if(nbLikes > nbDislikes)
			ans.insert(ingredient.first);
	}
	int maxScore = -1;
	pid_t c_pid = fork();
	vstr ans2;
	for(auto ingredient : ans)
		ans2.push_back(ingredient);
	if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (c_pid > 0) {
		for(int i=ans2.size()-1; i >= 0; --i){	
			auto usedIngredient = ans2[i];
			int score = getScore();
			ans.erase(usedIngredient);
			int newScore = getScore();
			for(auto ingredient : allIngredients){
				if(ans.find(ingredient.first) != ans.end() || usedIngredient == ingredient.first)
					continue;
				ans.insert(ingredient.first);
				int newScore2 = getScore();
				if(newScore2 <= newScore)
					ans.erase(ingredient.first);
				newScore = max(newScore2, newScore);
			}
			if(newScore < maxScore)
				ans.insert(usedIngredient);
			if(newScore > maxScore){
				ofstream newFile;
				newFile.open ("e_out_parent_"+ to_string(newScore) + ".txt");
				newFile << ans.size() << " ";
				for(auto ingredient : ans)
					newFile << ingredient << " ";
				newFile << "\n";
				newFile.close();
			}
			maxScore = max(maxScore, max(newScore, score));
			printf("Parent : [newScore = %d ] [maxScore = %d ] [score = %d ]\n", newScore, maxScore, score);
		}
        wait(nullptr);
	} else {
		For(i, ans2.size()){
			auto usedIngredient = ans2[i];	
			int score = getScore();
			ans.erase(usedIngredient);
			int newScore = getScore();
			for(auto ingredient : allIngredients){
				if(ans.find(ingredient.first) != ans.end() || usedIngredient == ingredient.first)
					continue;
				ans.insert(ingredient.first);
				int newScore2 = getScore();
				if(newScore2 <= newScore)
					ans.erase(ingredient.first);
				newScore = max(newScore2, newScore);
			}
			if(newScore < maxScore)
				ans.insert(usedIngredient);
			if(newScore > maxScore){
				ofstream newFile;
				newFile.open ("e_out_child_"+ to_string(newScore) + ".txt");
				newFile << ans.size() << " ";
				for(auto ingredient : ans)
					newFile << ingredient << " ";
				newFile << "\n";
				newFile.close();
			}
			maxScore = max(maxScore, max(newScore, score));
			printf("Child : [newScore = %d ] [maxScore = %d ] [score = %d ]\n", newScore, maxScore, score);
		}
        exit(EXIT_SUCCESS);
    }
	
	int newScore = getScore();
	debug() << imie(newScore);
	cout << ans.size() << " ";
	for(auto ingredient : ans)
		cout << ingredient << " ";
	cout << endl;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
