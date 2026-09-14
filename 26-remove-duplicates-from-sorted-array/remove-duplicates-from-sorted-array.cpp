class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 1;

        while(j < n) {
            while(j < n && nums[i] == nums[j]) {
                j++;
            }

            if(j < n) {
                i = i+1;
                swap(nums[i],nums[j]);
                j++;
            }
        }

        return i+1;
    }
};