class Solution {
public:
    int numSubaarayWithSumLessThanK(vector<int> &nums,int goal){
        if(goal < 0) return 0;
        
        int n = nums.size();

        int right = 0;
        int left = 0;

        int sum = 0;
        int count = 0;

        while(right < n){
            sum += nums[right];

            while(left < n && sum > goal){
                sum -= nums[left];
                left++;
            }

            // add length of the array as the length form the valid answer
            if(sum <= goal) count += right - left + 1;
            right++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1 = numSubaarayWithSumLessThanK(nums,goal);
        int count2 = numSubaarayWithSumLessThanK(nums,goal-1);

        return abs(count1-count2);
    }
};