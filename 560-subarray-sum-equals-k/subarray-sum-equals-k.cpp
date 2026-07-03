class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        // Brute Froce

        // for(int i = 0; i < nums.size();i++){
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++){
        //         sum += nums[j];
        //         if(sum == k) count++;
        //     }
        // }
        
        // Optimised Solution
        int n = nums.size();
        int cum = 0;

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            cum += nums[i];
            if(cum == k) count++;

            int rem = cum - k;

            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }

            mp[cum]++;
        }

        return count;
    }
};