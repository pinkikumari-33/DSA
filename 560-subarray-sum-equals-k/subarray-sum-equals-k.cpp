class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int currSum = 0;
        int count = 0;
        int left = 0;

        unordered_map<int,int> needed;
        needed[0] = 1;

        while(left < n) {
            currSum += nums[left];

            int rem = currSum - k;

            if(needed.find(rem) != needed.end()) {
                count += needed[rem];
            }
            
            needed[currSum]++;
            left++;
        }

        return count;
    }
};