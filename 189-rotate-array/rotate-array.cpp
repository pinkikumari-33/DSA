class Solution {
public:
    void reverse(vector<int>& nums,int i,int j) {
        while(i < j) {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int rotate = k % n;

        reverse(nums,0,n-1);
        reverse(nums,0,rotate-1);
        reverse(nums,rotate,n-1);
    }
};