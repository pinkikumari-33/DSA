class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return;

        int i = 0;
        int j = 0;

        while(j < n) {
            while(j < n && nums[j] == 0) {
                j++;
            }

            if(j < n) {
                swap(nums[i],nums[j]);
            
                i++;
                j++;
            }
        }
    }
};