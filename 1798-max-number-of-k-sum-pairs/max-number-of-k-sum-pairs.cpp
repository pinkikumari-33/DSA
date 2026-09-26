class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;

        int count  = 0;
        int left = 0;

        while(left < n) {
            int rem = k - nums[left];

            if(mp[rem] > 0) {
                count++;
                mp[rem]--;
            }
            else {
                mp[nums[left]]++;
            }


            left++;
        }

        return count;
    }
};