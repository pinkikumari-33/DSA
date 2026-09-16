class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();

        vector<int> ans(size,0);
        int p = 0;
        int n = 1;

        for(int x : nums) {
            if(x > 0) {
                ans[p] = x;
                p += 2;
            }

            else {
                ans[n] = x;
                n += 2;
            }
        }

        return ans;
       
    }
};