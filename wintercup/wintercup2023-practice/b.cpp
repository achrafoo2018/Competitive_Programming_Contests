#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long vectorToInt(const std::vector<int> &vec) {
    long long result = 0;
    for (int i = 0; i < vec.size(); i++) {
        result = result * 10 + vec[i];
    }
    return result;
}

set<long long > happy ;

void subsets(vector<int> &nums, int start, vector<int> &curr) {
    for (int i = start; i < nums.size(); i++) {
        curr.push_back(nums[i]);
        int length = curr.size();
        vector<int> temp = curr ;
        while (length <= 9) {
            do {
                // for (auto &num : temp) {
                //     cout << num << " ";
                // }
                // cout << endl;
                if(temp[0] != 0)
                    happy.insert(vectorToInt(temp)) ;
            } while (next_permutation(temp.begin(), temp.end()));
            for(auto x : curr)
                temp.push_back(x) ;
            length = temp.size() ;
        }
        subsets(nums, i + 1, curr);
        curr.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 3,4,5,6,7,8,9,0};
    vector<int> curr;
    subsets(nums, 0, curr);
    long long n,t ;
    cin >> t ;
    while(t--){
        cin >> n ;
        cout << *happy.upper_bound(n) << endl ;
    }
    return 0;
}