#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
	int i, j, mid, low = 0;
	int high = nums.size() - 1;
	while (low <= high){
		mid = (high + low) / 2;

		if(nums[mid] == target){
			for(i = mid; i < nums.size() && nums[i] == target; i++);
			for(j = mid; j >= 0 && nums[j] == target; j--);
			return vector<int>{j+1, i-1};
		}
		else if(nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return vector<int>{-1, -1};
}
int main(){
	vector<int> nums = {1};
	vector<int> res = searchRange(nums, 1);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}
