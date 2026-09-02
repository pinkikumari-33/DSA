class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        int len = 0;
        int pref = 0;
        mp[0] = -1;
        
        for(int i = 0; i < n; i++) {

            if(nums[i] == 0) pref -= 1;
            else pref += 1;

            if(mp.find(pref) != mp.end()) {
                len = max(len,i-mp[pref]);
            }
            else {
                mp[pref] = i;
            }
        }

        return len;
    }
};