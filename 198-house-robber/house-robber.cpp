class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> money(n,0);

        money[0] = nums[0];
        money[1] = max(nums[0],nums[1]);

        for(int i = 2; i < n; i++){

            // reject noney[i-1]
            // Accept money[i-2] + nums[i]
            // skips the adjacent number

            money[i] = max(money[i-2] + nums[i],money[i-1]);
        }

        return money[n-1];

    }
};