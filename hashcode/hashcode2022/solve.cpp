#include "bits/stdc++.h"
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


struct Project{
	string ProjectName;
	int NbDays, Score, BestBeforeDays, NbSkills;
	vector<pair<string, int>> skills;
};

struct less_than_key
{
    inline bool operator() (const Project& project1, const Project& project2)
    {
        return (project1.NbDays > project2.NbDays);
    }
};

void solve(){
	int C, P;
	cin >> C >> P;
	map<string, vector<pair<string, int>>> Contributors;
	For(i, C){
		string ContributorName;
		int NbSkills;
		cin >> ContributorName >> NbSkills;
		For(j, NbSkills){
			string skill;
			int level;
			cin >> skill >> level;
			Contributors[ContributorName].push_back({skill, level});
		}
	}
	map<string, map<int, vector<string>>> Skills;
	for(auto contributor : Contributors){
		for(auto skill : contributor.second){
			Skills[skill.first][skill.second].push_back(contributor.first);
		}
	}
	vector<Project> projects;
	For(i, P){
		Project project;
		cin >> project.ProjectName >> project.NbDays >> project.Score;
		cin >> project.BestBeforeDays >> project.NbSkills;
		For(j, project.NbSkills){
			string skill;
			int level;
			cin >> skill >> level;
			project.skills.push_back({skill, level});
		}
		projects.push_back(project);
	}
	sort(all(projects), less_than_key());
	vector<bool> doneProjects(P, false);
	bool projectDone = true;
	vector<pair<string, vector<string>>> output;
	while(projectDone){
		projectDone = false;
		int i = -1;
		while(++i < P){
			if(doneProjects[i])
				continue;
			bool ok = true;
			vector<string> workers;
			vector<int> workersLevel;
			map<string, string> used;
			for(auto skill : projects[i].skills){
				if(Skills.find(skill.first) == Skills.end()){
					ok = false;
					break;
				}
				bool found = false;
				for(auto cont : Skills[skill.first]){
					if(cont.first >= skill.second && !cont.second.empty()){
						for(auto worker : cont.second){
							if(used.find(worker) == used.end()){
								used[worker] = skill.first;
								found = true;
								workers.push_back(worker);
								workersLevel.push_back(cont.first);
								goto next;
							}
						}
					}
					// else if(abs(skill.second - cont.first) == 1){
					// 	for(auto worker : workers){
					// 		for(auto sk : Contributors[worker]){
					// 			if(skill.first == sk.first && sk.second >= skill.second && used[worker] != skill.first){
					// 				for(auto worker : cont.second){
					// 					if(used.find(worker) == used.end()){
					// 						used[worker] = skill.first;
					// 						found = true;
					// 						workers.push_back(worker);
					// 						goto next;
					// 					}
					// 				}
					// 			}
					// 		}
					// 	}
					// }
				}
				next:
				if(!found){
					ok = false;
					break;
				}
			}
			if(ok){
				projectDone = true;
				doneProjects[i] = true;
				output.push_back({projects[i].ProjectName, workers});
				For(ppp, projects[i].NbSkills){
					Skills[projects[i].skills[ppp].first][workersLevel[ppp]+1].push_back(workers[ppp]);
				}
				// i = -1;
			}
		}
		// debug() << imie(doneProjects);
	}
	cout << output.size() << endl;
	for(auto out : output){
		cout << out.first << endl;
		for(auto cont : out.second)
			cout << cont << " ";
		cout << endl;
	}
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