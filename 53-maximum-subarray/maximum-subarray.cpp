class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int len = 0;
        int left = 0;
        int right = 0;
        int maxSum = INT_MIN;
        int sum = 0;

        while(right < n) {
            sum += nums[right];

            if(sum < 0) {
                left = right;
                maxSum = max(maxSum,sum);
                sum = 0;
            }
            else {
                if(sum >= maxSum) {
                    maxSum = sum;
                    len = max(len, right-left + 1);
                }
            }

            right++;
        }

        return maxSum;
    }
};