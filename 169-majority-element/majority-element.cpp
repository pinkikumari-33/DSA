class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int n = nums.size();

        int curr = 0;

        for(int i = 0; i < n; i++) {
            if(freq == 0) {
                curr = nums[i];
            }

            if(curr == nums[i]) {
                freq++;
            }
            else {
                freq--;
            }
        }

        return curr;
    }
};