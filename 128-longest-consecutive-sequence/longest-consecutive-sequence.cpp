class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1) return n;

        map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = 0;
        int count = 0;

        for(auto it : mp) {
            if(mp.find(it.first+1) != mp.end()) {
                count++;
            }
            else {
                ans = max(ans,count);
                count = 0;
            }
        }

        return ans+1;
    }
};