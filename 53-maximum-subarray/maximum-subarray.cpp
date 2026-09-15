class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int pSum = 0;

        for(int i = 0; i < n; i++) {
            if(pSum < 0) {
                pSum = 0;
            }

            pSum += nums[i];
            ans = max(ans,pSum);
        }

        return ans;
    }
};