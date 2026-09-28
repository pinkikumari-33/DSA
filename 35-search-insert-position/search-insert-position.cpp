class Solution {
public:
    int helper(vector<int> &nums,int left,int right,int target) {

        int mid = (left + right) / 2;

        if(left > right) {
            return left;
        }

        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            return helper(nums,mid+1,right,target);
        }
        else {
            return helper(nums,left,mid-1,target);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        int n =  nums.size();
        return helper(nums,0,n-1,target);
    }
};