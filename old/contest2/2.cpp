class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        
        // 1. sort the given vector so all values are in ascending order
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            
            // initialize l and r and handle the duplicates
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            int x = nums[i];
            
            while(l < r){
                
                if(x + nums[l] + nums[r] == 0){
                    res.push_back(vector<int>{x,nums[l],nums[r]});
                
                // To handle duplicates 
                while(l < r && nums[l] == nums[l+1])
                    l++;
                while(l < r && nums[r] == nums[r-1])
                    r--;
                l++;
                r--;
                }
                // if sum of the number is less than zero
                else if(x + nums[l] + nums[r] < 0){
                    l++;
                }
                // if sum of the three number is greater then 0
                else{
                    r--;
                }
                
            }
            
            
        }
        return res;
    }
};