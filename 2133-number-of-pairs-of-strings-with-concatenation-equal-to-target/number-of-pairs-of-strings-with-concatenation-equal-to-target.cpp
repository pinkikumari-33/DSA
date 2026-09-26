class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                string s2 = nums[i] + nums[j];
                if(s2.compare(target) == 0) count++;

                string s1 = nums[j] + nums[i];
                if(s1.compare(target) == 0) count++;
            }
        }
    
        return count;
    }
};