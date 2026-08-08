class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
       
        int far = 0;

        for(int i = 0; i < n; i++){
            if(far < i) return false;
        
            if(far >= n-1){
                return true;
            }

            far = max(far, i + nums[i]);
        }

        return false;
    }
};