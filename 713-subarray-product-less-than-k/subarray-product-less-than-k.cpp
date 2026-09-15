class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int prod = 1;
        int ans = 0;

        int left = 0;
        int right = 0;

        while(right < n) {
            prod *= nums[right];

            while(left < n && prod > k ) {
                prod = prod / nums[left];
                left++; 
            } 

            if(prod < k) {
                ans += right - left + 1;
            }

            right++;
        }

        return ans;
    }
};