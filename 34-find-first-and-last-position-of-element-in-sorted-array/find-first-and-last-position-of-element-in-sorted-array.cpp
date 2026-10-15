class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto it = lower_bound(nums.begin(),nums.end(),target);
    
        if(it == nums.end()) return {-1,-1};

        int start = it - nums.begin();

        if(nums[start] != target) return {-1,-1};

        int end = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        return {start,end-1};
    }
};