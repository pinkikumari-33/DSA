class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int rotate = -1;

        for(int i = 1; i < n; i++) {
            if(nums[i-1] > nums[i]) {
                rotate = i;
                break;
            }
        }

        if(rotate == -1) return true;

        for(int i = 1; i < rotate; i++) {
            if(nums[i-1] > nums[i]) return false;
        }

        for(int i = rotate; i < n-1; i++) {
            if(nums[i] > nums[i+1]) return false;
        }

        if(nums[0] < nums[n-1]) return false;

        return true;
    }
};