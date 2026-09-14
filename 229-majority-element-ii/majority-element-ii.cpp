class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> maj;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto it  : mp) {
            if(it.second > n/3) {
                maj.push_back(it.first);
            }
        }

        return maj;
    }
};