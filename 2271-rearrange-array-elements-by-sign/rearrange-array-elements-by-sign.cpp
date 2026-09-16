class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> nArray;
        vector<int> pArray;

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                nArray.push_back(nums[i]);
            }
            else {
                pArray.push_back(nums[i]);
            }
        }

        int n1 = 0;
        int p = 0;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                nums[i] = pArray[p];
                p++;
            }
            else {
                nums[i] = nArray[n1];
                n1++;
            }
        }

        return nums;
    }
};