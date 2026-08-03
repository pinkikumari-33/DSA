class Solution {
public:
    int binarySearch(vector<int> &nums,int left,int right){
        int mid = left + (right-left)/2;

        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
            return mid;
        }

        else if(nums[mid-1] < nums[mid]){
            return binarySearch(nums,mid+1,right);
        }
        else{
            return binarySearch(nums,left,mid-1);
        }
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int ans = binarySearch(nums,1,n-2);

        return ans;
    }
};