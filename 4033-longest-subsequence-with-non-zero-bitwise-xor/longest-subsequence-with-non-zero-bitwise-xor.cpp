class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) count++;
            ans ^= nums[i];
            cout<<ans<<endl;
        }

        int i = 0;

        if(ans == 0 && count != n){
            return n - 1;
        }

        else if(count == n) return 0;
        else return n;
    }
};