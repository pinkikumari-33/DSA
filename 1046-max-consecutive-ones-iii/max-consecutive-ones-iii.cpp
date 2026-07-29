class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int right = 0;
        int left = 0;

        int maxLen = 0;
        int zeroes = 0;
        
        while(right < n){

            if(nums[right] == 0){
                zeroes++;
            }

            while(left < n && zeroes > k){
                if(nums[left] == 0){
                    zeroes--;
                }

                left++;
            }

            if(zeroes <= k){
                maxLen = max(maxLen,right-left+1);
            }

            right++;
        }

        return maxLen;
    }
};