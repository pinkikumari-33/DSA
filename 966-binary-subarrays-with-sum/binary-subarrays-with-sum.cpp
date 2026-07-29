class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            //if(sum == goal) count++;

            int rem = sum - goal;

            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }

            mp[sum]++;
        }

        return count;
    }
};