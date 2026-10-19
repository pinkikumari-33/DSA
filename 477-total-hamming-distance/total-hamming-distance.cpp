class Solution {
public:
    int hammingDistance(int &x) {
        int res = x;
        int count = 0;

        while(res > 0 ) {
            int ans = res & 1;
            if(ans == 1) count++;
            res = res >> 1;
        }

        return count;
    }

    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        int max = *max_element(nums.begin(),nums.end());

        while(max > 0) {
            int c = 0;

            for(int i = 0; i < n; i++) {
                int res = nums[i] & 1;
                if(res == 1) c++;
                nums[i] = nums[i] >> 1;
            }

            res += (n-c) * c;
            max = max >> 1;
        }
        

        return res;
    }
};