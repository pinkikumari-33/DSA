class Solution {
public:
    int robMoney(vector<int> &nums,vector<int> &money,int start,int end){
        money[start] = nums[start];
        money[start+1] = max(nums[start],nums[start+1]);

        for(int i = start+2; i <= end; i++){
            money[i] = max(money[i-2] + nums[i],money[i-1]);
        }

        return money[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        vector<int> money(n,0);

        int res1 = robMoney(nums,money,0,n-2);
        int res2 = robMoney(nums,money,1,n-1);

        return max(res1,res2);
    }
};