class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        auto it = lower_bound(nums.begin(),nums.end(),target);

        if(it == nums.end()) return n;

        int start = it - nums.begin();
        //if(nums[start] != target) return start -1;

        return start;
    }
};