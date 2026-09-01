class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        int len = 0;
        int pSum = 0;
        mp[0] = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) pSum -= 1;
            else pSum += 1;

            if(mp.find(pSum) != mp.end()) {
                len = max(len, i - mp[pSum]);
            }
            else {
                mp[pSum] = i;
            }
            
        }

        return len;
    }
};