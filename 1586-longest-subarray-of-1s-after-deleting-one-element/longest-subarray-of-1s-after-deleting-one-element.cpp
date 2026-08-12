class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = 0;
        int count = 0;
        int ans = 0;

        while(right < n){
            int num = nums[right];

            if(num == 0) count++;

            while(count > 1){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }

            if(count <= 1){
                ans = max(ans,(right-left + 1));
            }

            right++;
        }

        return ans-1;
        
    }
};