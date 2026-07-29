class Solution {
public:

    int subArrayWithSumLessThanK(vector<int> &nums, int k){
        if(k < 0) return 0;

        int n = nums.size();

        int right = 0;
        int left = 0;

        int count = 0;
        int sum = 0;

        while(right < n){
            sum += nums[right];

            while(left < n && sum > k){
                sum -= nums[left];
                left++;
            }

            if(sum <= k){
                count += right-left+1;
            }

            right++;

        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i] = nums[i]%2 == 0 ? 0 : 1;
        }
        
        int num1 = subArrayWithSumLessThanK(nums,k);
        int num2 = subArrayWithSumLessThanK(nums,k-1);

        return abs(num1-num2);
    }
};